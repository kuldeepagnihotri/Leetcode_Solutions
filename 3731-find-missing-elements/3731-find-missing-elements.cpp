class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxi = nums[n-1];
        int mini= nums[0];
        unordered_set<int> st(nums.begin(),nums.end());
        vector<int> ans;
        for(int i = mini +1 ;i<maxi;i++){
           if(st.find(i)==st.end())
           ans.push_back(i);
        }
        return ans;
    }
    
};