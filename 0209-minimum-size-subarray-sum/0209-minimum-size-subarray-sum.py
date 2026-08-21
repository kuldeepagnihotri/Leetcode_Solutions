class Solution(object):
    def minSubArrayLen(self, target, nums):
        left=0
        sum=0
        mini=float('inf')
        for i in range (len(nums)):
            sum+=nums[i]

            while(sum>=target):
               mini=min(mini,i-left+1)
               sum-=nums[left]
               left+=1
        if mini==float('inf'):
            return 0
        return mini    