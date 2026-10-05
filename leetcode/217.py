from typing import List
class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        s = set()
        for x in nums:
            if x not in s:
                s.add(x)
            else:
                return True
        return False

s = Solution()
nums = [1,2,3,1]
print(s.containsDuplicate(nums), end = '')