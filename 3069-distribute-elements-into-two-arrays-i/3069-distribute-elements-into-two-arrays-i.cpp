class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> nums1;
        vector<int> nums2;

        nums1.push_back(nums[0]);
        nums2.push_back(nums[1]);

        for(int i = 2; i < nums.size(); i++) {
            int s1 = nums1.size();
            int s2 = nums2.size();

            if(nums1[s1 - 1] > nums2[s2 - 1]) {
                nums1.push_back(nums[i]);
            }
            else {
                nums2.push_back(nums[i]);
            }
        }

        int index = 0;

        for(int i = 0; i < nums1.size(); i++) {
            nums[index++] = nums1[i];
        }

        for(int i = 0; i < nums2.size(); i++) {
            nums[index++] = nums2[i];
        }

        return nums;
    }
};