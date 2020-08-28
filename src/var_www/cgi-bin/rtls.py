#!/usr/bin/python

import os
import sys
import subprocess
import utils
import cgi

if __name__ == '__main__':
  print "Content-type: text/html"
  print
  print "<html>"
  print "<head>"
  print "<title>Start Mapper_MRPT</title>"
  #print '<META http-equiv="Refresh" content="3;URL=/">'
  print "</head>"
  print "<body>"
  print "<h1>Mapper_MRPT</h1>"
  print "<pre>"

  try:
    #res=subprocess.check_output(['python', 'rtcmd.py', 'list', '-l'])
    res=subprocess.check_output(['python', 'rtcmd', 'list', '-l'])
    print res
  except:
    print "Error: rtcmd"

  print os.environ['REMOTE_ADDR']

  print "</pre>"
  print "<hr>"
  print '[<a href="/">Back</a>]'
  print "</body>"
  print "</html>"

  sys.stdout.flush()
