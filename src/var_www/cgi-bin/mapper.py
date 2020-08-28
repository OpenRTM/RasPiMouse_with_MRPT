#!/usr/bin/python

import os
import sys
import cgi
import subprocess
import utils

if __name__ == '__main__':
  form = cgi.FieldStorage()
  try:
    cmd = form["cmd"].value
  except:
    cmd = None

  try:
    disp = form["disp"].value
  except:
    disp = os.environ['REMOTE_ADDR']
  
  print "Content-type: text/html"
  print
  print "<html>"
  print "<head>"
  print "<title>Start Mapper_MRPT</title>"
  #print '<META http-equiv="Refresh" content="3;URL=/">'
  print "</head>"
  print "<body>"
  print "<h1>Mapper_MRPT</h1>"

  if cmd == "start":
    print "Start Mapper system components"

  elif cmd == "connect":
    print "Connect Mapper system components"

  elif cmd == "stop":
    print "Terminate Mapper system components"

  elif cmd == "activate":
    print "Activate Mapper system components"

  elif cmd == "deactivate":
    print "Deactivate Mapper system components"

  else:
    print "No such command: ", cmd
  
  print "<hr>"
  print '[<a href="/">Back to the top page.</a>]'
  print "</body>"
  print "</html>"

  sys.stdout.flush()

  utils.daemonize()

  if cmd:
    arg=['/usr/local/openrtm/mapper.sh', cmd, disp]
    p = subprocess.Popen(arg)
