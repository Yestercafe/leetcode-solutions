#!/usr/bin/env python3
from components.migrate import migrate
from components.enrich_id import enrich_id
from components.git import git

migrate('Yescafe', '.', './leetcode-everyday')
enrich_id('.', 4)
git('addp')
git('commit')
git('sync')
