#!/usr/bin/python3

import os
import sys
import cgi
import subprocess
import utils

if __name__ == '__main__':
  print("Content-type: text/html")
  print("")
  print("<html>")
  print("<head>")
  print("</head>")
  print("<body>")

  print("<hr>")
  print('[<a href="/">Back to the top page.</a>]')
  print("</body>")
  print("</html>")

  sys.stdout.flush()

  utils.daemonize()

  arg=['/usr/local/openrtm/bin/RPLidarRTC.sh']
  p = subprocess.Popen(arg)
