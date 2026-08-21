class Solution(object):
    def intersection(self, nums1, nums2):
       nums1.sort()
       nums2.sort()
       s=set()
       for i in range(len(nums1)):
            for j in range(len(nums2)):
                if nums1[i]==nums2[j]:
                    s.add(nums1[i])
                    
       return list(s)
        