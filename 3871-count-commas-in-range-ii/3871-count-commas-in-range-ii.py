class Solution(object):
    def countCommas(self, n):
        count = 0
        p = 1000

        while p <= n:
            count += n - p + 1
            p *= 1000

        return count