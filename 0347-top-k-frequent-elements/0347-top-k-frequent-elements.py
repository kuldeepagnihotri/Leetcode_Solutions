class Solution(object):
    def topKFrequent(self, nums, k):

        freq = {}

        for x in nums:
            freq[x] = freq.get(x, 0) + 1

        sorted_freq = sorted(freq, key=freq.get, reverse=True)

        return sorted_freq[:k]