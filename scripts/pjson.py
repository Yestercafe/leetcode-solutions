import json
from dataclasses import dataclass
from scripts.constants import *


class Singleton(object):
    def __new__(cls, *args, **kwargs):
        if not hasattr(cls, '_instance'):
            orig = super(Singleton, cls)
            cls._instance = orig.__new__(cls, *args, **kwargs)
        return cls._instance


@dataclass
class PJson(Singleton):
    export = None

    def __init__(self):
        with open(PROBLEM_LIST_JSON) as fp:
            self.export = json.load(fp)['stat_status_pairs']
