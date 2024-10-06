class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        s1 = sentence1.split()
        s2 = sentence2.split()

        # Ensure s1 is the shorter sentence
        if len(s1) > len(s2):
            s1, s2 = s2, s1

        n1, n2 = len(s1), len(s2)

        # Use two pointers to check prefix and suffix similarity
        start, end = 0, n1 - 1
        while start < n1 and s1[start] == s2[start]:
            start += 1

        while end >= 0 and s1[end] == s2[n2 - (n1 - end)]:
            end -= 1

        # Check if all words in s1 were matched in either the prefix or the suffix of s2
        return start > end
