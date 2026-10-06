class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        '''
        approach:
            * use a map to keep track of target-nums[i]
        '''
        mpp = dict()
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in mpp:
                return [mpp[complement], i]
            mpp[nums[i]] = i
        return [-1, -1]

s = Solution()
nums = [2,7,11,15]
target = 9
l = s.twoSum(nums, target)
print(l, end = '')