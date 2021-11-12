import re
import sys
import os


def err(info: str):
    print('E: ' + info, file=sys.stderr)


def mkdir(pathname, show_err=True):
    try:
        os.mkdir(pathname)
    except FileExistsError:
        if show_err:
            err("File `%s' exists." % pathname)
        return False
    return True


def run(command: str, prompt=True):
    if prompt:
        print('%', command)
    return os.system(command)


def log(info, show: bool):
    if show:
        print(info)


def get_added(path='.'):
    added = set()
    pattern = r'^\d'
    for filename in os.listdir(path):
        if re.match(pattern, filename):
            pid = int(filename.split('-')[0].lstrip('0'))
            added.add(pid)
    return added
