#!/usr/bin/python
import os
import sys
import subprocess

if __name__ == '__main__':
  print "Content-type: text/html"
  print

  try:
    res=subprocess.check_output(['pgrep', 'omniNames'])
    if res:
      print "omniNames already running"
    else:
      print "omniNames running?"
  except:
    print "omniNames is not running"

