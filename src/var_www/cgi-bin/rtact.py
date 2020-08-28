#!/usr/bin/python

import os
import sys
import subprocess
import utils
import cgi

hostname = os.uname()[1]

if __name__ == '__main__':
  form = cgi.FieldStorage()
  try:
    rtcname = form["rtc"].value
  except:
    rtcname = None

  print "Content-type: text/html"
  print
  print "<html>"
  print "<head>"
  print "<title>Activate RTC</title>"
  print '<META http-equiv="Refresh" content="3;URL=/">'
  print "</head>"
  print "<body>"
  print "<h1>Activate RTC</h1>"
  print "<pre>"

  try:
    rtc_name="%s.host_cxt/%s0.rtc" % (hostname, rtcname)
    print rtc_name
    res=subprocess.check_output(['python', 'rtcmd', 'activate', rtc_name])
    print res
  except:
    print "Error: rtcmd"


  print "</pre>"
  print "<hr>"
  print '[<a href="/">Back</a>]'
  print "</body>"
  print "</html>"

  sys.stdout.flush()
