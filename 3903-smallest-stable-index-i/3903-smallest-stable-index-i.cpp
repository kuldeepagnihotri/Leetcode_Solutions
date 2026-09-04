class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        for(int i =0;i<nums.size();i++){
        int maxElement=*max_element(nums.begin(),nums.begin()+i+1);
        int minElement=*min_element(nums.begin()+i,nums.end());
        int result=maxElement-minElement;
        if(result<=k){
            return i;
        }
        
        }
            return -1;
    }
};