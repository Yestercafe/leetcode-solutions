import os
import re
import argparse

def cmd(command):
  print(command)
  os.system(command)

def enrich_id(path, min_length):
  filenames = os.listdir(path)
  pattern = r'^\d'
  for filename in filenames:
    if not re.match(pattern, filename):
      continue

    problem_id = filename.split('-')[0]
    length = len(problem_id)
    if length > min_length:
      print('adjust min_length to {}'.format(length))
      enrich_id(path, length)
      return
    elif length == min_length:
      print('reserve "{}/{}"'.format(path, filename))
      continue

    cmd('mv "{}/{}" "{}/{}{}"'.format(path, filename, \
                                      path, '0'*(min_length-length), filename))

if __name__ == '__main__':
  parser = \
    argparse.ArgumentParser(description=\
                            'Increase length of problem ids to min_length.')
  parser.add_argument('-p', '--path', type=str, default='.', \
                      help='path which will be operated')
  parser.add_argument('-l', '--min_length', type=int, default=4, \
                      help='min length of problem id')
  args = parser.parse_args()

  enrich_id(args.path, args.min_length)
