#!/usr/bin/env python3
import os
import argparse
import time

def cmd(command):
  print('$ ' + command)
  return os.system(command)

def git(instruction, msg='Commit at {}'.format(time.time())):
  if instruction == 'addp':
    cmd('ls | grep "^\d" | xargs git add')
  if instruction == 'adda':
    cmd('git add -A')
  if instruction == 'commit':
    cmd('git commit -m "{}"'.format(msg.strip('\'"')))
  if instruction == 'sync':
    if cmd('git pull') == 0:
      cmd('git push')
  if instruction == 'log':
    cmd('git --no-pager log --graph --oneline -10')

if __name__ == '__main__':
  parser = \
    argparse.ArgumentParser(description=\
                          'My Git CLI')
  parser.add_argument('instruction', type=str, \
                      choices=['addp', 'adda', 'commit', 'sync', 'log'], \
                      help='instruction')
  parser.add_argument('-m', '--msg', type=str,
                      default='Commit at {}'.format(time.strftime("%Y-%m-%d %H:%M:%S", \
                                                    time.gmtime())), \
                      help='optional commit message')
  args = parser.parse_args()

  git(args.instruction, args.msg)
