RaspberryPi 3B+へOSのインストール
----------------------------------
RasPiMouse2019のハードウェアの組み立ての前に、搭載するCPUボード(RaspberryPi 3B+)に
OSのインストールとRasPiMouse2019を動作指せるデバイスドライバのインストールを行ってください。

RaspberryPi 3B+にRaspbianをインストール
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Raspbianのインストールは、`オフィシャルサイト <https://www.raspberrypi.org/downloads/raspbian/>`_ 
からNOOBS.zipをダウンロードし、RaspbianをインストールするmicroSDカードに展開します。

次に、NOOBS.zipを展開したmicroSDカードをRaspberryPi 3B+に挿入し、ディスプレイ、マウス、キーボードを接続して、
通常起動を行い、画面の指示通りに進めるとRaspbian Busterがインストールされます。

また、sshdを有効にするために NOOBS.zipを展開した場所に ssh という名前のファイルを作成してください。

インストール終了後、ネットワークに接続してOSのアップデートを行ってください。

起動モードをCUIに変更
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
NOOBSを使ってRaspbianをインストールすると、グラフィックモードで起動します。
RasPiMouse2019では、通常、ディスプレイを接続しませんので、CUIモードで起動するように設定ます。
起動モードの設定には、raspi-configを用います。

新規にターミナルを起動し、下記のコマンドを実行してください。

.. code-block::

  $ sudo raspi-config

上記のコマンドを実行すると piユーザのパスワードを要求しますので、
Raspbianをインストール時に設定したパスワードを入力してください。
すると、下のようなメニュー画面が表示されますので、
3 Boot Options -> B1 Desktop/CLI の順で選択し、CUIモード(B1またはB2)に変更してください。

.. image:: img/raspi-config.png

変更終了後、再起動してCUIモードで起動することを確認してください。

RaspberryPiMouseのドライバのインストール
----------------------------------------
搭載するCPUボードへのOSのインストール終了後、RaspberryPiMouse2019にCPUボードを取付け
モータ、センサ制御用のデバイスドライバのインストールを行います。

RaspberryPiMouseのドライバのインストール
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
RaspberryPiMouseのドライバは、`株式会社アールティのオフィシャルGithub <https://github.com/rt-net/RaspberryPiMouse>`_ 
に公開されています。
RaspberryPiMouseのドライバは、ソースコードからビルドしインストールします。

まず、オフィシャルサイトからソースコードをダウンロードします。

.. code-block::

    $ mkdir ~/src
    $ cd src
    $ git clone https://github.com/rt-net/RaspberryPiMouse

ドライバのソースコードのダウンロードが正常に終了後、'utils'の下に移動し、
ドライバモジュールのビルドとテストインストールを行います。
ドライバモジュールのビルドには、kernel ヘッダーファイルが必要になりますので、事前にaptコマンドで
インストールしてください。

ドライバモジュールのビルドとテストインストールは、'utils/build_install.bash'で実行することができます。

.. code-block::

    $ sudo apt install raspberrypi-kernel-headers
    $ cd ~/src/RaspberryPiMouse/utils
    $ ./build_install.bash

上記のコマンドを実行後、「ピッ」と音がすれば、ドライバモジュールがインストールされています。
この時、src/drivers　にドライバモジュールとテスト用のバイナリが生成されていますので、
RaspberryPiMouseの動作確認を行うことができす。

この状態では、ドライバモジュールは、~/src/RaspberryPiMouse/src/drivers にあります。
再起動直後にドライバモジュールを読み込むようにするには、ドライバモジュールを
システム用のディレクトリにコピーする必要があります。

そこで、下記のコマンドを実行し、/lib/modules/4.19.75-v7+/kernel/dirversへ
rtmouse.koをコピーしてください。

.. code-block::

    $ cd ~/src/RaspberryPiMouse/src/drivers
    $ sudo cp rtmouse.ko /lib/modules/4.19.75-v7+/kernel/drivers
    $ sudo depmod

Raspbianの設定変更とスクリプトの導入
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
次に、再移動直後に RaspberryPiMouseのドライバモジュールが利用できるように設定を行います。
RaspberryPiMouseのドライバは、SPI機能とI2C機能を有効にする必要がありますので、
raspi-configコマンドを使って、SPI機能、I2C機能を「入」にしてください。
SPI機能は、5 Interfacing Options -> P4 SPI で有効化することができ、
I2C機能は、5 Interfacing Options -> P5 I2C で有効化することがでます。

さらに、RaspberryPiMouseの起動時にドライバモジュールの読み込むように、設定を行います。

まず、下記の内容のrtmouse.shを作成し、/etc/init.d/にコピーしてください。

.. code-block::

  #!/bin/bash
  #
  #
  ### BEGIN INIT INFO
  # Provides:          rtmouse
  # Required-Start:    $all
  # Required-Stop:     
  # Default-Start:     2 3 4 5
  # Default-Stop:
  # Short-Description: RT_Mouse_Driver
  # Description:       RaspPiMouse Driver
  ### END INIT INFO
  SCRIPTNAME=rtmouse.sh
  PROC_FILE=/proc/modules
  GREP=/bin/grep
  MODPROBE=/sbin/modprobe
  MODULE_NAME=rtmouse
  DEP_MODULE_NAME=mcp320x
  [ -f $PROC_FILE ] || exit 0
  [ -x $GREP ] || exit 0
  [ -x $MODPROBE ] || exit 0
  RES=`$GREP $MODULE_NAME $PROC_FILE`
  install_rtmouse(){
    if [ "$RES" = "" ]; then
      $MODPROBE $MODULE_NAME
      echo "Module Install $MODULE_NAME"
    else
      echo "Module '$MODULE_NAME' is already installed"
    fi
  }
  remove_rtmouse(){
    if [ "$RES" = "" ]; then
      echo "Module '$MODULE_NAME' isn't installed yet."
    else
      $MODPROBE -r $MODULE_NAME
      $MODPROBE -r $DEP_MODULE_NAME
      echo "Module '$MODULE_NAME' is rmoved."
    fi
  }

  case "$1" in
    start)
    install_rtmouse
    sleep 1
    /bin/chmod a+rw /dev/rt*
    ;;
    stop)
    remove_rtmouse
    ;;
    status)
      if [ "$RES" = "" ]; then
        echo "Module '$MODULE_NAME' isn't installed yet."
        exit 0
      else
        echo "Module '$MODULE_NAME' is already installed"
        exit 0
      fi
    ;;
    *)
      echo "Usage: $SCRIPTNAME {start|stop|status}" >&2
      exit 3
  esac
  exit 0

次に、rtmouse.koを起動時systemdによる自動起動を行うために、下記の内容のファイルを作成し、
/etc/systemd/system/rtmouse.service という名前で配置してください。

.. code-block::

  [Unit]
  Description=rtmouse driver

  [Service]
  Type=oneshot
  ExecStart=/etc/init.d/rtmouse.sh start
  ExecReload=/etc/init.d/rtmouse.sh restart
  ExecStopt=/etc/init.d/rtmouse.sh stop

  [Install]
  WantedBy=multi-user.target

最後に、上記で作成してsystemdの設定の有効化を行うために下記のコマンドを実行してください。

.. code-block::

    $ sudo sysremctl enable rtmouse

以上で、systemdによるドライバをインストールできるようになりますので、再起動して動作確認を行ってください。
起動時に「ピッ」という音が鳴れば、ドライバのインストールが正常に動作しています。
