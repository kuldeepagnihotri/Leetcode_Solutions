class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
auto t=0, nonZero=0;
for(auto &n : nums){
    nonZero |= n>0;
    t^=n;
}
return nonZero * (nums.size()-!t);
    }
};