class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // using sliding window
        int i =0;
        int j =0;
        int sum=0;
        int maxSum=INT_MIN;
        while(j<nums.size()){
        sum+=nums[i];
        maxSum=max(sum,maxSum);
        i++;
        if(sum<0) sum=0;
         j++;
        }
       
       return maxSum;  
    }
   
};