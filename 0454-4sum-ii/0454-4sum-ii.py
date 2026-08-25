from collections import Counter
class Solution(object):
    def fourSumCount(self, nums1, nums2, nums3, nums4):
       mp=Counter()
       for a in nums1:
        for b in nums2:
            mp[a+b]+=1

       count=0
       for c in  nums3:
        for d in  nums4:
            count+=mp[-(c+d)]
       return count            
        