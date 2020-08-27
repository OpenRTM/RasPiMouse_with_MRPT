RasPiMouse2019のナビゲーションを行うRTCは、
下記の8つのRTCがあります。

- RaspberryPiMouseRTC
- RPLidarRTC
- Mapper_MRPT
- Localization_MRPT
- PathPlanner_MRPT
- SimplePathFollower
- MapServer
- NavigationManager

これらのRTCの中でMapServerとNavigationManagerの
2つのコンポーネントは、Javaで実装されており、
他の6つはC++で実装されています。

ここでは上記のRTCをソースコードからビルドする方法について説明します。

ナビゲーションRTC群のソースコードの取得
---------------------------------------------
まず最初にソースコードを取得します。
上記のRTCのソースコードは全てGithub上に公開されていますので、
gitコマンドでダウンロードしてください。

.. code-block::

    $ mkdir ~/src
    $ cd ~/src
    $ git clone https://github.com/hara-jp/RaspbarryPiMouseRTC.git
    $ git clone https://github.com/hara-jp/RPLidarRTC.git
    $ git clone https://github.com/hara-jp/Mapper_MRPT.git
    $ git clone https://github.com/hara-jp/Localization_MRPT.git
    $ git clone https://github.com/hara-jp/PathPlanner_MRPT.git
    $ git clone https://github.com/hara-jp/SimplePathFollower.git
    $ git clone https://github.com/hara-jp/MapServer.git
    $ git clone https://github.com/hara-jp/NavigationManager.git
  

RTC(C++)のビルド
------------------------
次に、C++で実装されているRTCをビルドします。
OpenRTM-aist-1.2.1-Releaseでは、cmakeとmakeを使った
ビルドシステムを使用します。
C++で実装されたRTCのビルド手順はすべて同じですので、
RaspberryPiMouseRTCの場合を例に説明していきます。

まず、ソースコードのあるディレクトリに移動し、
ビルド用のディレクトリ "build-1" を生成します。

.. code-block::

    $ cd ~/src/RaspbarryPiMouseRTC
    $ mkdir build-1

次に、ビルド用ディレクトリに移動し、cmakeを実行します。

.. code-block::

    $ cd build-1
    $ cmake ..

cmakeコマンドでエラーが発生しなければ、
makeコマンドを実行してRTCをビルドします。

.. code-block::

    $ make


RTC(C++)のパッケージ化
----------------------------
OpenRTM-aist-1.2.1-ReleaseのRTC Builderで生成した
cmakeファイルでは、cpackコマンドによるdebパッケージの
生成を行うことができます。

そこで、下記のコマンドを実行してdebパッケージを生成してください。

.. code-block::

    $ cd ~/src/RaspbarryPiMouseRTC/build-1
    $ cpack


RTC(Java)のビルド
------------------------
次に、Javaで実装されているRTCをビルドします。
OpenRTM-aist-1.2.1-Releaseでは、Java版のRTCにはantコマンドを使用します。
Java版のRTCもC++版と同様にビルド手順は全て同じです。
そのため、ここではNavigationManagerの例で説明していきます。

ソースコードのあるディレクトリに移動し、下記のようにantコマンドを実行します。

.. code-block::

    $ cd ~/src/NavigationManager
    $ ant -f build_NavigationManager.xml

ビルトが成功すれば、bin, classesの下に生成された.classファイルが生成されます。

RTC(Java)のパッケージ化
----------------------------
OpenRTM-aist-1.2.1-Releaseでは、
Java版のビルド後にcmakeコマンドとcpackコマンドで
debパッケージを生成することができます。

そこで、下記のようにdebパッケージ生成用のディレクトリ build-1を作成して、
cmake, cpackを実行して下さい。

.. code-block::

    $ cd ~/src/NavigationManager
    $ mkdir build-1
    $ cd build-1
    $ cmake ..
    $ cpack
