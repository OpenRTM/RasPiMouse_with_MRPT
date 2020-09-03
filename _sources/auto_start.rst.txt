.. -*- coding: utf-8 -*-

RTC自動起動設定
===========================================

.. contents:: 目次
  :depth: 3


RTコンポーネントの自動起動に関してなのですが、以前のRaspbianでは
/etc/rc.local の中に起動起動スクリプトを記載することで実行することができました。

しかしながら現在のRaspbian Busterでは、
OS起動時にの自動実行プロセスは systemd により制御されており、
/etc/systemd/system の下にプロセス起動の設定ファイルを配置し、
systemctl コマンドで有効化を行うことで実現することができます。

しかしながら、RTCではネームサーバーが必要であるが、
omniorb4-nameserverのサービスが正常に動作しないという事例が報告されています。
これは、omniNamesの起動時に、/var/lib/omniorb/omninames-raspberrypi.[log, dat]
などのファイルが残っていると起動に失敗する場合があるからです。
したがって、omniorb-nameserverの起動前に上記のファイルを削除するサービスをインストールすれば
解決可能です。

例えば、まず、下記の内容の /usr/local/openrtm/remove-nameserver-logs.sh というスクリプトを作成します。

.. code-block::

    #/bin/bash
    /bin/rm -f /var/lib/omniorb/omninames-raspberrypi.*

次に、下記の内容のサービス設定ファイル 
/etc/systemd/system/clear_omniname_logs.service

.. code-block::

    [Unit]
    Description=Remove log and dat of omniorb4-nameserver
    Before=omniorb4-nameserver.service

    [Service]
    Type=oneshot
    ExecStart=/usr/bin/sudo /usr/local/openrtm/remove-nameserver-logs.sh

    [Install]
    WantedBy=multi-user.target

を作成し、下記のコマンドでインストールしてください。

.. code-block::

    $ sudo systemctl enable clear_omniname_logs.service


この設定で、omniNamesの自動起動は可能ですが、外部のクライアントPC上のopenrtp等のツールから
アクセスできない場合があります。
そのため、omniNamesの起動スクリプトである /etc/init.d/omniorb4-nameserver の33行目の部分に
"-ORBendPointPublish giop:tcp:192.168.11.1:"　を下記のように追記することで、外部からのアクセスが可能になります。

.. code-block::

    startcmd="start-stop-daemon --start --quiet --background --pidfile $PIDFILE --make-pidfile --exec $DAEMON -- -errlog $LOGFILE -ORBendPointPublish giop:tcp:192.168.11.1:"

ナビゲーションRTC群の自動起動については、
起動スクリプトにバックグラウンド処理で別のコマンドの呼出し等を行うと正常に動作しない場合がある
ことが報告されているため、起動時にRTC群を自動起動することは推奨することができません。

そのため、前述のWebブラウザによるRTC及びRTCで構成されるシステムスクリプトを
CGI経由で呼出し、実行させるようにしてください。
