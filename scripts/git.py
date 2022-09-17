import time
import scripts.utils as utils


def auto_commit(commit_info: str = ''):
    add_all()
    if len(commit_info) == 0:
        commit('Auto commit: ' + time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()))
    else:
        commit(commit_info)

def commit(msg: str):
    utils.run('git commit -m "' + msg + '"')

def add_all():
    utils.run('git add -A')

