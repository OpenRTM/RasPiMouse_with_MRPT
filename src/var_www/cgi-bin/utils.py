#!/usr/bin/python

import os
import sys
import subprocess
import glob

#
#
def daemonize():
  try:
    pid=os.fork()
  except:
    print( "ERROR in fork1" )
    os._exit(0)

  if pid > 0:
    os._exit(0)

  try:
    os.setsid()
  except:
    print( "ERROR in setsid" )

  try:
    pid=os.fork()
  except:
    print( "ERROR in fork2" )

  if pid > 0:
    os._exit(0)

  os.umask(0)
  os.close(sys.stdin.fileno())
  os.close(sys.stdout.fileno())
  os.close(sys.stderr.fileno())


#
#
def start_omniNames():
  logfiles=glob.glob("/tmp/omninames-*.*")
  for fn in logfiles:
    os.remove(fn)

  arg=['/usr/bin/omniNames', '-start', '2809', '-datadir', '/tmp']
  p = subprocess.Popen(arg)
