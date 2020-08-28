#!/usr/bin/python

import os
import sys
import subprocess
import utils
import cgi

if __name__ == '__main__':
  print "Content-type: text/html"
  print

  try:
    res=subprocess.check_output(['python', 'rtcmd', 'list', '-l'])
    print res
  except:
    print "Error: rtcmd"
