class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        n = len(skill)
        if n == 2:
            return skill[0] * skill[1]
        if sum(skill) % (n/2) != 0:
            return -1
        
        average = sum(skill) / (n/2)
        total = 0

        for i in range(n//2):
            num_1 = skill.pop()
            if abs(average - num_1) in skill:
                num_2 = skill.pop(skill.index(abs(average - num_1)))
                total += num_1 * num_2
            else:
                return -1
        
        return total
# ------------------------------------------------------------------------
class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        n = len(skill)
        if n == 2:
            return skill[0] * skill[1]
        if sum(skill) % (n/2) != 0:
            return -1
        
        average = sum(skill) // (n/2)
        total = 0
        
        skill_count = {}
        for s in skill:
            skill_count[s] = skill_count.get(s, 0) + 1

        for s in list(skill_count.keys()):
            if skill_count[s] > 0:
                num_1 = s
                num_2 = average - num_1
                if num_2 in skill_count and skill_count[num_2] > 0:
                    pairs = min(skill_count[num_1], skill_count[num_2])
                    if num_1 == num_2:
                        pairs //= 2
                    total += pairs * num_1 * num_2
                    skill_count[num_1] -= pairs
                    skill_count[num_2] -= pairs
                else:
                    return -1
        
        return int(total)