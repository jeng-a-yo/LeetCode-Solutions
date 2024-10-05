class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        reminders = [0] * k

        for num in arr:
            reminders[num % k] += 1
        
        if reminders[0] % 2 != 0:
            return False

        for i in range(1, (k // 2) + 1):
            if i == k - i:
                if reminders[i] % 2 != 0:
                    return False
            elif reminders[i] != reminders[k - i]:
                return False

        return True
