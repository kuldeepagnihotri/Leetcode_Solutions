class Solution(object):
    def longestConsecutive(self, nums):
        if not nums:
            return 0

        nums.sort()

        count = 1
        maxi = 1

        for i in range(1, len(nums)):
            if nums[i] == nums[i-1] + 1:
                count += 1

            elif nums[i] == nums[i-1]:
                continue

            else:
                count = 1

            maxi = max(maxi, count)

        return maxi