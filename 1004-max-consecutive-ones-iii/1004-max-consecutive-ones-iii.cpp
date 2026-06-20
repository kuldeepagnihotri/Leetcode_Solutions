class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int i=0, j =0 , zeros=0, maxLen =0;
    int len =0;
    while(j<nums.size()){
        if(nums[j]==0) zeros++;
        if(zeros>k){
            if (nums[i]==0) zeros--;
            i++;
        }
        if(zeros<=k)
        len = j-i+1;
        maxLen = max( len , maxLen);
        j++;
    } 
    return maxLen;   
    }
};