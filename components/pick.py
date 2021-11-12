#!/usr/bin/env python3
import json
import os

LC_PREFIX = 'https://leetcode.com/problems/'

def get_problem_name(pick_id):
    with open('components/problems.json') as fp:
        for info in json.load(fp)['stat_status_pairs']:
            if info['stat']['frontend_question_id'] == pick_id:
                title = info['stat']['question__title']
                slug = info['stat']['question__title_slug']
                return {'title': title, 'slug': slug}
    pass

def mk_problem_dir(pick_id, problem_name):
    dir_name = '%.4d-%s' % (pick_id, problem_name['slug'])
    try:
        os.mkdir(dir_name)
    except FileExistsError:
        return False
    with open(dir_name + '/readme.md', 'w+') as w:
        w.write('# %d. %s\n' % (pick_id, problem_name['title']))
        w.write(LC_PREFIX + problem_name['slug'] + '\n')
    return True

def pick_problem(pick_id):
    problem_name = get_problem_name(pick_id)
    if not mk_problem_dir(pick_id, problem_name):
        print('Dir existed!')
    else:
        print('Add %d-%s succeeded!' % (pick_id, problem_name['title']))

def main():
    pick_id = int(input('ID you pick: '))
    pick_problem(pick_id)

if __name__ == '__main__':
    main()
