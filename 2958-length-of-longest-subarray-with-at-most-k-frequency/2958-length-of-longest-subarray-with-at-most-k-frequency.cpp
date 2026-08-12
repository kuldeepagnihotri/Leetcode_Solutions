class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int left =0;
        int ans=0;
        for(int right =left;right<nums.size();right++){
         freq[nums[right]]++;
         //invalid window
         while(freq[nums[right]]>k){
         freq[nums[left]]--;
         left++;
        }
      // valid window
      ans=max(ans,right-left+1);
    }
    
    return ans;
    }
};