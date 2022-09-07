class Solution:
    def reorderSpaces(self, text: str) -> str:
        words = text.split()
        cnt_spc = len(text) - len(''.join(words))
        if len(words) < 2:
            return words[0] + ' ' * cnt_spc
        quo, rem = cnt_spc // (len(words) - 1), cnt_spc % (len(words) - 1)
        return (' ' * quo).join(words) + ' ' * rem

