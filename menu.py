#!/usr/bin/env python3

import argparse
import scripts.migrate as migrate
from scripts.problem import Problem
from scripts.pjson import PJson
from scripts.update_problem_list import update_problem_list
from scripts.git import auto_commit
import scripts.utils as utils


def main():
    parser = argparse.ArgumentParser(description='An automation script for this repo.')
    parser.add_argument('instruction', type=str, choices=['migrate', 'pick', 'info', 'update_readme', 'update_problem_list', 'auto_commit', 'stats'])
    parser.add_argument('-i', '--problem_id', type=int)
    args = parser.parse_args()

    if args.instruction == 'migrate':
        migrate.migrate_from_repo('leetcode-everyday', 'Yescafe')
    elif args.instruction == 'pick':
        Problem.pick_problem(args.problem_id)
    elif args.instruction == 'info':
        print(Problem(args.problem_id, PJson().export))
        return
    elif args.instruction == 'update_readme':
        migrate.update_readmes()
    elif args.instruction == 'update_problem_list':
        update_problem_list()
    elif args.instruction == 'auto_commit':
        auto_commit()
        return
    elif args.instruction == 'stats':
        utils.run('ls | grep "^\d" | wc -l')
        return
    auto_commit()



if __name__ == '__main__':
    main()