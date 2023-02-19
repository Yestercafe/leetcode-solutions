class Solution:
    def bestHand(self, ranks: List[int], suits: List[str]) -> str:
        if len(set(suits)) == 1: return "Flush"
        r = set(ranks)
        if len(list(filter(lambda x : x[1] >= 3, Counter(ranks).items()))) == 1: return "Three of a Kind"
        if len(r) == 5: return "High Card"
        else: return "Pair"

