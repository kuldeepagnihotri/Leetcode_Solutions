class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int>freq;
        vector<int> v;
        //count frequency
        for( auto num:nums){
            freq[num]++;
        }

// find dupliactes
      for(auto it:freq){
        if(it.second > 1)
        v.push_back(it.first);
      }
      return v;
    }
};