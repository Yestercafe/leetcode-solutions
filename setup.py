#!/usr/bin/env python3
from components.migrate import migrate
from components.enrich_id import enrich_id
from components.git import git
import os

def cmd(command):
  print('$ ' + command)
  os.system(command)

migrate('Yescafe', '.', './leetcode-everyday')
enrich_id('.', 4)
cmd('git add ./leetcode-everyday')
git('addp')
git('commit')
git('sync')
