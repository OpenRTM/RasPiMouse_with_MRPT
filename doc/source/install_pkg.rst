.. -*- coding: utf-8 -*-
:tocdepth: 2

OpenRTM-aist-1.2.1-Releaseのインストール
----------------------------------------
`OpenRTM-aistのオフィシャルサイト <https://openrtm.org/openrtm/ja/node/6912>`_
から「一括インストールスクリプト(pkg_install_raspbian.sh)」をダウンロードし、インストールを行います。

下記のコマンドを実行してください。
OpenRTM-aist-1.2.1-Release のC++版、Python版(Python2.7)、Java版及びOpenRTP, Rtshellがインストールされます。

.. code-block::

  $ wget https://raw.githubusercontent.com/OpenRTM/OpenRTM-aist/master/scripts/pkg_install_raspbian.sh
  $ sudo sh ./pkg_install_raspbian.sh -l all --yes

OpenRTM-aist-1.2.1-ReleaseのJava版では、OpenJDK-8が必要となりますが、
上記の一括インストールスクリプトでは、openjdk-8はインストールされませんので、
別途インストールが必要です。

Raspbian Butterでは、openjdk-8のパッケージが提供されていますので、
下記のコマンドでインストールし、デフォルトの設定をopenjdk-8に変更してください。

.. code-block::

  $ sudo apt-get install openjdk-8-jdk
  $ sudo update-alternatives --config java
  
     選択肢    パス                                          優先度  状態
  ------------------------------------------------------------
   * 0            /usr/lib/jvm/java-11-openjdk-amd64/bin/java      1111      自動モード
     1            /usr/lib/jvm/java-11-openjdk-amd64/bin/java      1111      手動モード
     2            /usr/lib/jvm/java-8-openjdk-amd64/jre/bin/java   1081      手動モード
  
   現在の選択 [*] を保持するには <Enter>、さもなければ選択肢の番号のキーを押してください: 2
   update-alternatives: /usr/bin/java (java) を提供するためにマニュアルモードで /usr/lib/jvm/java-8-openjdk-amd64/jre/bin/java を使います

以上で、OpenRTM-aist-1.2.1-Releaseのインストールは終了です。

rplidar_sdkのインストール
------------------------------------
次に、RasPiMouse2019に搭載さているレーザー距離センサを利用するためのライブラリ 
rplidar_sdkをインストールします。

rplidar_sdkは、`Github <https://github.com/hara-jp/rplidar_sdk>`_
に公開されていますので、ダウンロードしインストールします。
下記のコマンドでライブラリをビルドしてください。

.. code-block::

  $ cd ~/src
  $ git clone https://github.com/hara-jp/rplidar_sdk
  $ cd ~/src/rplidar_sdk/sdk
  $ make

上記のビルドが成功すれば、 sdk/output/Linux/Release　にライブラリ librplidar_sdk.a
が生成されているはずですので確認してください。

次に、ビルドしたライブラリおよびヘッダーファイル、
cmakeファイルを下記のコマンドでインストールしてください。

.. code-block::

  $ sudo make install

上記のコマンドの実行後には /usr/local/rplidar_sdk　にライブラリ、ヘッダーなどがインストールされています。

また、RPLidarはUSBシリアルを使用します。
通常、USBシリアルのデバイスファイルへのアクセスは、管理者権限のみに限られています。
そのため、USBシリアルデバイスファイル（/dev/ttyUSB0）をユーザ権限でアクセスするために
udev（/lib/udev/rules.d/50-udev-default.rules）の設定を変更します。

.. code-block::

  /lib/udev/rules.d/50-udev-default.rules

の最下部から2行目に下記の一行を追記してください。

.. code-block::

  KERNEL=="ttyUSB[0-9]*", MODE="0666"

以上で、udevの設定は終了です。
再起動後には、"/dev/tyyUSB*" のファイルがユーザ権限で利用可能です。

MRPTのインストール
------------------
移動ロボットのナビゲーションを行うRTC群は、MRPT(Mobile Robot Programing Toolkit)を利用し、
ナビゲーション用の地図の作成や目的地への経路計画などを行っています。
RasPiMouse2019で使用しているRaspbianには、このMRPTライブラリ(libmrpt)の
パッケージが用意されていますので、libmrptをインストールします。

libmrptは、下記のようにaptコマンドでインストールすることができます。

.. code-block::

    $ sudo apt-get install libmrpt-dev


ナビゲーションRTC群のパッケージインストール
-------------------------------------------
次に、RasPiMouse2019のナビゲーションのためのRTC群のパッケージを
`Github <https://github.com/hara-jp/RasPiMouse2019-OpenRTM/blob/master/pkgs.tgz?raw=true>`_ 
からダウンロードしてください。

このパッケージには、ナビゲーションRTC群(debファイル)、
ナビゲーション実行のための設定、起動ファイル群(openrtm.tgz)、
RTC群、ネームサーバの起動、終了等のためのWebコンテンツ及びCGIスクリプト(web.tgz)
が含まれています。

パッケージをダウンロード後、下記のコマンドで展開してください。

.. code-block::

  $ cd ~/
  $ wget https://github.com/hara-jp/RasPiMouse2019-OpenRTM/blob/master/pkgs.tgz?raw=true -O pkgs.tgz
  $ tar xzvf pkgs.tgz

ナビゲーションRTC群は、dpkgコマンドでインストールすることができますので、
下記のコマンドでインストールしてください。

.. code-block::

  $ cd ~/pkgs
  $ sudo dpkg -i *.deb

これでナビゲーションRTC群は、/usr/share/openrtm-1.2/components の下にインストールされます。


ナビゲーションRTC群の起動・設定ファイル群のインストール
----------------------------------------------------------
次に、RasPiMouse2019でナビゲーションRTC群の設定、起動スクリプトの
ファイル群を展開します。
前述しましたが、設定、起動ファイル群は openrtm.tgz になりますので、
下記のコマンドで /usr/local の下に展開してください。

.. code-block::

  $ cd ~/pkgs
  $ sudo tar xzvf openrtm.tgz -C /usr/local


ナビゲーションRTC群操作用のWebインターフェースのインストール
-------------------------------------------------------------------
最後に、ナビゲーションRTC群を制御するためのWebコンテンツ及びCGIのファイル群(www.tgz)
を展開します。

下記のコマンドでファイル群をインストールしてください。

.. code-block::

  $ cd ~/pkgs
  $ sudo tar xzvf www.tgz -C /var

以上でナビゲーションRTC群のバイナリ、設定ファイル群のインストールは終了です。
