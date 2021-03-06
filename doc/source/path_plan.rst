.. -*- coding: utf-8 -*-

概要
^^^^^^^^
このシステムでは、前述のナビゲーション地図作成システムにより生成した
地図とRasPiMouse2019に搭載したLiDARの情報をもとにMontecarlo localization
を行い、ナビゲーション地図上で指定した目的地までのナビゲーションを行うシステムです。

目的地は、NavigationManagerに表示されたナビゲーション地図上のポイントをクリックすることで、
位置と姿勢を入力することができます。

このシステムでは、RaspberryPiMouseRTC, RPLidarRTC, Localization_MRPT, 
PathPlanner_MRPT, SimplePathFollower, MapServer, NavigationManagerの7つのRTCを使用します。
また、各RTC間の接続は、下図のようになります。

.. image:: img/path_plan.png


RTCの起動
^^^^^^^^^^^^^
RTCの起動は、Webブラウザを利用する場合には、トップページの第5セクション "PathPlan"の部分を使用します。
ナビゲーションRTCのシステムに対しては、
下図のように「Start」、「Connect」、「Activate」、「Deactivate」、「Stop」の5つのオペレーションがあります。

.. image:: img/web4.png

ナビゲーション（経路計画）システムに必要なRTCの起動に「Start」を押下してください。
起動メッセージのページに遷移後、3秒後に自動でトップページに戻ります。

トップページに移行後、第2セクションの  "RTC List" には、現在起動中のRTCの一覧が
表示されますが、RTCによって起動時間が異なりますので、全てのRTCが起動完了するまで
しばらくお待ちください。

NavigationManagerをRasPiMouse側で起動する際は、あらかじめX ServerをローカルPCで
起動させたうえで、 このシステムを起動させてください。 
NavigationManagerはGUI表示を伴いますので、 おそらく一番最後に起動すると思います。
全てのRTCが起動すると、下図のようなNavigationManagerの操作パネルが表示されます。

NavigationManagerをローカルPC側で起動する場合は、ローカルPCでは X Serverを起動させずに、
Webブラウザからシステムを起動します。この際、RasPiMouse側のNavigationManagerは、
X Serverへ接続できませんので、エラーで終了します。一方、MapServerはそのまま起動
してしまいますので、Webページ上部の RT-Components のセクションにて、MapServer の
「Stop」リンクをクリックして停止させます。

NavigationManager/MapServerがRasPiMouseで起動していないことを確認したら、
前節でローカルPC側に ダウンロードした NavigationManager/MapServerを
それぞれ NavigationManager.bat、 MapServer.bat をクリックして起動します。

なお、前節でダウンロードしたNavigationManager/MapServer は、RasPiMouse側で
起動するRTCと 同じネームサーバの同じホストコンテキスト raspberrypi.host_cxt 
の下に登録されます。 これであたかも、これらのRTCがRasPiMouse上で起動されたように見えます。

また、第2セクションの「List」を押下すると下図のようにRTCのリストが表示されます。

.. image:: img/path_plan-start.png

Webブラウザを使用せずに、ターミナルでRasPiMouse2019にログインする場合には、
下記のコマンドを入力すると上記と同じ結果が得らえます。

.. code-block::

  $ /usr/local/openrtm/bin/path_plan.sh start

ナビゲーション（経路計画）構築（ポートの接続）
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
必要なRTCの起動後は、ナビゲーション（経路計画）システムを構成するために、
各RTCのポートの接続を行います。
最終的なシステム構成は、概要で表示した図の通りになります。
この構成を外部のRT System Editorを使って手動で接続しても良いのですが、
第4セクションの「Connect」ボタンを押下することで必要な接続を行うことができます。

ポートの接続後、第2セクションの「List」を押下すると下図のようなリストが得られます。

.. image:: img/path_plan-connect.png

また、rtcmdを用いて graphコマンドを実行すると下図のようなシステム構成図を得ることができます。

.. image:: img/path_plan-graph.png

また、Webブラウザを使用せずに、ターミナルでRasPiMouse2019にログインする場合には、
下記のコマンドを入力すると上記と同じ結果が得らえます。

.. code-block::

  $ /usr/local/openrtm/bin/path_plan.sh connect

ナビゲーション（経路計画）の実行
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
RTCのポート接続が完了後、ナビゲーション（自己位置同定）を行います。
本システムに係る5つのRTCをアクティベートしてください。

RTCのアクティベート
~~~~~~~~~~~~~~~~~~~~~~~~~
RTCのアクティベートの方法は、
Webブラウザ、ターミナルでログイン後にコマンド入力、
クライアントPC上のopenrtp、rtcmd等の外部ツールのいづれかを使用してください。

ここでは、Webブラウザとターミナルでログイン後のコマンドライン入力の2つの方法を紹介します。

Webブラウザでは、第5セクションの「Activation」ボタンを押下することで全てのRTCをアクティベートすることができます。
ターミナルからのコマンドライン入力では、下記のコマンドで同様に全てのRTCをアクティベートすることが可能です。

.. code-block::

  $ /usr/local/openrtm/path_plan.sh activate

すべてのRTCを有効化すると、下図のようにNavigationManagerの右側のペインにナビゲーション地図が表示され、
現在のRasPiMouse2019の位置が原点付近で探索され、表示されます。

.. image:: img/localize-start-mgr.png

現在のデフォルト設定では、/usr/local/openrtm/testMap.yamlを使用しますが、
他のナビゲーション地図を利用する場合には、
/usr/local/openrtm/etc/MapServer.confのパラメータを適宜修正してください。

移動目標位置の入力
~~~~~~~~~~~~~~~~~~~~~~~~~
次に、NavigationManagerのナビゲーション地図上をマウスでクリックすることで、
移動目標の入力を行います。

ナビゲーション地図の任意の位置でクリックすると、下のようなダイアログが表示され、
目標座標と姿勢を入力することができます。

.. image:: img/navi-goal.png

目標位置は、このダイアログの上部に表示されており、目標姿勢はダイアログ内に表示された
円の円周をクリックすることで指定することができます。

目標姿勢を確認後、「OK」ボタンをクリックして移動目標の位置と姿勢を決定してください。
すると、下図に示すようにナビゲーション地図上に目標位置と姿勢が表示されます。

.. image:: img/navi-goal-start.png


移動経路の生成
~~~~~~~~~~~~~~~~~~~~~~~~~
次に、目標位置までの経路生成を行います。
経路生成は、NavigationManagerのGUIパネルの上部の「Plan Path」ボタンを押下することで
生成することができます。

経路生成の結果（成功したか否か）は、NavigationManagerの右下にあるメッセージパネルに表示されます。

RasPiMouse2019のナビゲーション
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
経路計画が正常に終了すれば、「Follow」ボタンを押下することで、
RasPiMouse2019を移動させることができます。

生成さえた経路に沿ったナビゲーションは、
SimplePathFollowerコンポーネントがNavigationManager経由で
得られた動作経路とLocalization_MRPTによって推定された自己位置を
もとに動作命令を生成しています。

ナビゲーション終了後は、下図のようになります。

.. image:: img/path_plan-end.png

この時Localization_MRPTの自己位置推定によっては正しい動作をすることができません。
ナビゲーション（自己位置推定）システムの部分にも記載していますが、
推定精度はオドメトリの精度に大きく依存しており、車輪のスリップが発生すると
正しいナビゲーションを行うことができません。

そのため、システム動作のまえに車輪等のハードウェアの管理を適切に行うようにしてください。

ナビゲーション（経路計画）システムの終了
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
ナビゲーション（経路計画）システムの終了は、
Webブラウザの第3セクションの「Stop」ボタンを押下するか、
ターミナルでログイン後に下記のコマンド入力を行うことで行ってください。

.. code-block
  $ /usr/local/openrtm/bin/path_plan.sh stop
