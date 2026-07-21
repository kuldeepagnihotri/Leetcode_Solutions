class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums;
        // this is the brute force approach optimal will be done by using megre and quick sort to get complexity (nlog(n))
    }
};