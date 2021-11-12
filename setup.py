#!/usr/bin/env python3
from components.migrate import migrate
from components.git import git
import os

def cmd(command):
  print('$ ' + command)
  os.system(command)

migrate('Yescafe', '.', './leetcode-everyday')
cmd('git add ./leetcode-everyday')
git('addp')
git('commit')
git('sync')
