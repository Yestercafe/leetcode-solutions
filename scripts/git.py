import time
import scripts.utils as utils


def auto_commit():
    add_all()
    commit('Auto commit: ' + time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()))

def commit(msg: str):
    utils.run('git commit -m"' + msg + '"')

def add_all():
    utils.run('git add -A')

