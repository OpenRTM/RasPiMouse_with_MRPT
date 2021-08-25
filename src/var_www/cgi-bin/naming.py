#!/usr/bin/python3

import os
import sys
import subprocess
import utils

if __name__ == '__main__':
  print("Content-type: text/html")
  print("")
  print("<html>")
  print("<head>")
  print("<title>RTM Naming Service</title>")
  print('<META http-equiv="Refresh" content="3;URL=/">')
  print("</head>")
  print("<body>")


  try:
    res=subprocess.check_output(['pgrep', 'omniNames'])
    if res:
      print("omniNames already running")
    print("</body>")
    print("</html>")
  except:
    print("Start omniNames")
    print("</body>")
    print("</html>")
    sys.stdout.flush()

    utils.daemonize()
    utils.start_omniNames()

