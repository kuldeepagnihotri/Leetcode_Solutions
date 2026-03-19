class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minDIST = INT_MAX;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==target)
            minDIST=min(minDIST,abs(i - start));
        }
        return minDIST;
    }
};