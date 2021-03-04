#!/usr/bin/env python3
import os
import re
import argparse

def cmd(command):
  print(command)
  os.system(command)

def migrate(name, path, source, tmpfile='./find-result'):
  os.system('find "{}" -iname "*{}*" > "{}"'.format(source, name, tmpfile))

  existences = set()
  pattern = r'^\d'
  for filename in os.listdir(path):
    if not re.match(pattern, filename):
      continue
    problem_id = filename.split('-')[0].lstrip('0')
    existences.add(problem_id)

  with open(tmpfile) as fp:
    for filepath in fp.readlines():
      filepath = filepath.strip()
      problem_id = filepath.split('/')[-2].split('_')[-1]
      if problem_id in existences:
        continue

      basepath = filepath[:filepath.rfind('/')]
      with open(basepath + '/READEME.md') as readme:
        problem_name = readme.readlines()[4].strip().split('/')[-1]

      problem_id_name = '{}-{}'.format(problem_id, problem_name)
      filename = filepath.split('/')[-1]

      cmd('mkdir -p "{}/{}"'.format(path, problem_id_name))
      cmd('cp "{}" "{}/{}/{}"'.format(filepath, path, \
                                      problem_id_name, filename))

  os.system('rm -f "{}"'.format(tmpfile))

if __name__ == '__main__':
  parser = \
    argparse.ArgumentParser(description=\
                            'Migrate problem solutions from source.')
  parser.add_argument('name', type=str, \
                      help='keyword you want to find')
  parser.add_argument('-d', '--dest', type=str, default='.', \
                      help='destination path')
  parser.add_argument('-s', '--src', type=str, default='./leetcode-everyday', \
                      help='source/find path')
  args = parser.parse_args()

  migrate(args.name, args.dest, args.src)
