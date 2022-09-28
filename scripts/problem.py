import os
from dataclasses import dataclass
from scripts.constants import *
import scripts.utils as utils
from scripts.pjson import PJson


class Problem:
    pid: int
    title: str
    slug: str
    difficulty: str
    is_paid: bool

    def __init__(self, problem_id, export):
        for json_dict in export:
            if json_dict['stat']['frontend_question_id'] == problem_id:
                self.pid = json_dict['stat']['frontend_question_id']
                self.title = json_dict['stat']['question__title']
                self.slug = json_dict['stat']['question__title_slug']
                self.difficulty = {1: 'Easy', 2: 'Medium', 3: 'Hard'}[json_dict['difficulty']['level']]
                self.is_paid = json_dict['paid_only']

    def get_fullname(self):
        return '%s-%s' % (self.pid, self.slug)

    def wake_up(self):
        self.mkdir(False)
        self.update_readme()

    def mkdir(self, show_err=True):
        return utils.mkdir(self.get_fullname(), show_err)

    def update_readme(self):
        with open('./' + self.get_fullname() + '/readme.md', 'w+') as fp:
            fp.write('# %s. %s\n\n' % (self.pid, self.title))
            if self.is_paid:
                fp.write('# ONLY FOR PAID\n\n')
            fp.write('Difficulty: %s\n\n' % self.difficulty)
            fp.write('URL: %s\n\n' % (LEETCODE_PROBLEM_PREFIX + self.slug))

    def __str__(self):
        return '[pid: %s, title: %s, slug: %s, difficulty: %s, is_paid: %d]'\
               % (self.pid, self.title, self.slug, self.difficulty, self.is_paid)

    def _pick(self):
        if self.mkdir():
            self.update_readme()
            print("Pick `%s-%s'." % (self.pid, self.title))
        else:
            print('Pick error.')

    @classmethod
    def pick_problem(cls, pid):
        problem = cls(pid, PJson().export)
        problem._pick()
