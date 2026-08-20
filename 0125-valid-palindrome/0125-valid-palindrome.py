class Solution(object):
    def isPalindrome(self, s):
        s=s.strip()
        s=''.join(c.lower() for c in s if c.isalnum())
        n=s[::-1]
        return n==s