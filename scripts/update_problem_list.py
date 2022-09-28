import json
from scripts.constants import *
import scripts.utils as utils

def update_problem_list():
    utils.run('wget https://leetcode.cn/api/problems/all/ -O ' + PROBLEM_LIST_JSON)

    file_name = PROBLEM_LIST_JSON
    # codes from https://github.com/chat-code/leetcode-everyday/blob/master/utility/clean_json.py
    info_lst = []
    with open(file_name) as fh:
        for info in json.load(fh)['stat_status_pairs']:
            item = {
                'stat': {
                    'frontend_question_id': info['stat']['frontend_question_id'],
                    'question__title': info['stat']['question__title'],
                    'question__title_slug': info['stat']['question__title_slug'],
                },
                'difficulty': {},
            }
            if not info['paid_only']:
                item['paid_only'] = info['paid_only']
                item['difficulty']['level'] = info['difficulty']['level']
                info_lst.append(item)

    with open(PROBLEM_LIST_JSON, 'w') as fh:
        info_all = {
            'stat_status_pairs': info_lst,
        }
        json.dump(info_all, fh)

    utils.run('python3 -m json.tool %s > %s.tmp' % (PROBLEM_LIST_JSON, PROBLEM_LIST_JSON))
    utils.run('mv %s.tmp %s' % (PROBLEM_LIST_JSON, PROBLEM_LIST_JSON))
