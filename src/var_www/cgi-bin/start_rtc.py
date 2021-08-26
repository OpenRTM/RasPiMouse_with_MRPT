#!/usr/bin/python3

import os
import sys
import cgi
import subprocess
import utils

if __name__ == '__main__':
  form = cgi.FieldStorage()
  try:
    rtc = form["rtc"].value
  except:
    rtc = None

  try:
    disp = os.environ['REMOTE_ADDR']
  except:
    disp = ""
  
  print("Content-type: text/html")
  print("")
  print("<html>")
  print("<head>")
  print("<title>Start RTC</title>")
  print("</head>")
  print("<body>")

  if rtc:
    print("Start RTC ", rtc)

  else:
    print("No such RTC: ", rtc)
  
  print("<hr>")
  print('[<a href="/">Back to the top page.</a>]')
  print("</body>")
  print("</html>")
  sys.stdout.flush()

  utils.daemonize()

  if rtc:
    arg=['/usr/local/openrtm/bin/'+rtc+'.sh', disp]
    p = subprocess.Popen(arg)
