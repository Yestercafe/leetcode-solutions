class Solution:
    def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], report: List[str], student_id: List[int], k: int) -> List[int]:
        offline = list(zip(student_id, report))
        offline.sort(key = lambda p: p[0])
        p = set(positive_feedback)
        n = set(negative_feedback)
        for i, (sid, rep) in enumerate(offline):
            tokens = rep.split()
            score = 0
            for token in tokens:
                if token in p:
                    score += 3
                if token in n:
                    score -= 1
            offline[i] = (offline[i][0], score)
        offline.sort(key = lambda p: p[1], reverse = True)
        return [p[0] for p in offline][:k]

