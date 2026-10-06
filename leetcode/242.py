class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        hashmap = [0]*26
        for c in s:
            hashmap[ord(c)-ord('a')] += 1
        for c in t:
            hashmap[ord(c)-ord('a')] -= 1

        for x in hashmap:
            if x != 0:
                return False
        return True

sol = Solution()
s = "anagram"
t = "nagaram"
print(sol.isAnagram(s, t), end='')