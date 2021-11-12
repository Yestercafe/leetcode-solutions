from scripts.constants import *
import os
from scripts.problem import Problem
from scripts.pjson import PJson
import scripts.utils as utils


def migrate_from_repo(src: str, keyword: str, show_log=False, forced=False):
    added = utils.get_added()

    utils.run('find "%s" -iname "*%s*" > "%s"' % (src, keyword, TMP_FILENAME), show_log)
    with open(TMP_FILENAME) as fp:
        for find_path in fp.readlines():
            find_path = find_path.strip()

            pid = int(find_path.split('/')[-2].split('_')[-1])
            if not forced and pid in added:
                continue
            problem = Problem(pid, PJson().export)
            utils.log(problem, show_log)
            filename = find_path.split('/')[-1]

            problem.wake_up()
            utils.run('cp -f "%s" "%s/%s"' % (find_path, problem.get_fullname(), filename), show_log)

    utils.run('rm -f ' + TMP_FILENAME, show_log)


def update_readmes():
    added = utils.get_added()

    for pid in added:
        problem = Problem(pid, PJson().export)
        problem.update_readme()
