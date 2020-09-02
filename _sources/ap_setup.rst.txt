.. -*- coding: utf-8 -*-
:tocdepth: 2

RaspberryPiMouseの無線LANのアクセスポイント化
------------------------------------------------
RasPiMouse2019を使用する場合、無線LANを外部ネットワークに接続して
使用しても良いのですが、複数のRasPiMouse2019で講習会を行うことを
想定すると個々のRasPiMouse2019の無線LANをアクセスポイント化し
クライアントPCとダイレクト接続して利用する方が便利です。

そこで、ここではRasPiMouse2019の無線LANをアクセスポイント化について
説明します。

RasPiMouse2019の無線LANのアクセスポイント化には、hostapdとdnsmasq というソフトウェアが
が必要になります。
下記のようにapt-getコマンドでインストールしてください。

.. code-block::

  $ sudo apt-get install hostapd dnsmasq

次に、hostaptdとdnsmasqの設定を行います。
hostapdの設定を行うために、/etc/hostapd/hostapd.conf を下のような内容で作成してください。

.. code-block::

  interface=wlan0
  driver=nl80211
  ssid=<SSID>
  hw_mode=g
  channel=4
  wmm_enabled=0
  macaddr_acl=0
  auth_algs=1
  wpa=2
  wpa_key_mgmt=WPA-PSK
  rsn_pairwise=CCMP
  wpa_passphrase=<PASSWORD>

上記のファイル内容で <SSID> 及び <PASSWORD> は、RasPiMouse2019は
個々の機体ごとに任意の文字列で設定してください。(ただし、<PASSWORD>は8文字以上にしてください)

次にRasPiMouse2019の機体のIPアドレスを固定アドレスで運用できるように設定します。
Raspbian Busterでは、dhcpcdというDHCPクライアントによって各ネットワークデバイス
IPアドレスを設定しています。
dhcpcdの設定ファイルは /etc/dhcpcd.conf になりますので、
このファイルに下記のように固定アドレスの設定を追記してください。

.. code-block::

    ....
    ....

  interface wlan0
  static ip_address=192.168.11.1/24
  static routers=192.168.11.1
  static domain_name_servers=192.168.11.1 8.8.8.8
  nohook wpa_supplicant

ここでは、RasPiMouse2019の無線LANのIPアドレスを 192.168.11.1/24 という
プライベートアドレスに設定しています。
また、Raspbian Busterの dhcpcdでは、無線LANのネットワークデバイスの設定
には、wpa_supplicantというマネージャーを自動起動してしまいます。
そのため、無線LANアクセスポイントを利用する場合には、wpa_supplicantの起動を
抑制するために "nohook wpa_supplicant" を末尾に追加しています。

ただし、このwpa_suplicantの自動起動機能の抑制は、全ての無線LAN機器に
対して有効になりますので、他のUSBの無線LANを付けてもwap_supplicantが
機能せず、無線LANの自動接続しませんので注意してください。

次に、無線LANアクセスポイントに接続するクライアントPCへIPアドレスを割り当てる
DHCPサーバー機能を有効にします。

DHCPサーバーとして使用する dnsmasq の設定ファイルは、/etc/dnsmasq.conf にありますので、
下記の内容を追記してください。

.. code-block::

   no-resolv
   no-poll
   dhcp-range=192.168.11.10,192.168.11.20,12h
   server=192.168.11.1

ここでは、クライアントPCに配布するIDアドレスとして、192.168.11.10～192.168.11.20の
11個のアドレスに設定しており、そのリース期間は12時間になっています。
また、dhcpサーバーとして機能するIPアドレスは、192.168.11.1になっています。

上記の3つのファイルの追加・修正で内蔵無線LANデバイスのアクセスポイント化の設定は
終了ですが、hostapdがsystemdで起動できない状態のママになっています。

そこで下記のコマンドを実行して、hostapdを起動時に自動実行するように設定してください。

.. code-block::

  $ sudo systemctl unmask hostapd
  $ sudo systemctl enable hostapd

最後に、Java版の外部からのアクセスを有効にするために、/etc/hostsを変更します。
Raspbian Buster の初期設定では、ホスト名である "raspberrypi" のIPアドレスの設定が、

.. code-block::

  127.0.1.1    raspberrypi

と記載されています。
このままでは、Java版のRTCに外部のPCからアクセスすることができません。

したがって、上記の部分を下のように修正してください。

.. code-block::

  192.168.11.1    raspberrypi

以上で、RasPiMouse2019の内蔵無線LANデバイスをアクセスポイント化することができましたので、
再起動を実施てアクセスポイントになっていることを確認してください。

Webサーバーのセットアップ
--------------------------
RasPiMouse2019では、CGIを経由して外部PC上のWebブラウザから
ネームサーバの起動、RTC群の制御を行うことができます。

この節では、CGIを利用するためにapache2を導入と設定を行っていきます。
まずは、下記のコマンドを実行してapache2のインストールとCGIの有効化を実行してください。

.. code-block::

  $ sudo apt-get install apache2
  $ sudo ln -s /etc/apache2/mods-available/cgi.load /etc/apache2/mods-enabled/cgi.load

次に、CGIの設定をファイルの指定のために、
apache2のデフォルト設定ファイルを下のように修正します。

/etc/apache2/sites-available/000-default.conf をエディタで開き、
28行目にある下記の行のコメントをはずします。

.. code-block::

  Include conf-available/serve-cgi-bin.conf

次に、CGIプログラムとしてPythonプログラムファイルを使うためにMIME設定を変更します。

/etc/apache2/mods-available/mime.conf のファイルの219行目にある
下記の行のコメントをはずし '.py'を追加します。

.. code-block::

  AddHandler cgi-script .cgi .py

最後に、CGIプログラムを配置する場所を /var/www/cgi-bin に変更します。
/etc/apache2/conf-available/serve-cgi-bin.conf の11行目と12行目に記載されている
CGIプログラムの設置場所を下記のように変更してください。

.. code-block::

  ScriptAlias /cgi-bin/ /var/www/cgi-bin
  <Directory "/var/www/cgi-bin"> 

以上で、apache2のインストールとCGIの設定は終了です。
apache2を再起動するために下記のコマンドを実行してください。

.. code-block::

  $ sudo service apache2 restart


クライアント用PCの設定
----------------------------
RasPiMouse2019のナビゲーションRTC群の中でNavigationManagerは、Javaで実装され
GUIパネルを含んでいます。

そのため RasPiMouse2019上でNavigationManagerを動作させるには、
クライアントPCにX-WindowのXサーバーが必要になります。
Linux端末等UNIX系OSには、GUIシステムとしてXだサーバが利用されていますが、
Windows10などのMicrosoftのOSには、Xサーバーを別途インストールする必要があります。

Windows上で実行可能なXサーバーとして、
`有償のX410 <https://www.microsoft.com/ja-jp/p/x410/9nlp712zmn9q?activetab=pivot:overviewtab>`_
または `VcXsrv <https://sourceforge.net/projects/vcxsrv/>`_
がありますので、どちらのアプリケーションをインストールしてください。
