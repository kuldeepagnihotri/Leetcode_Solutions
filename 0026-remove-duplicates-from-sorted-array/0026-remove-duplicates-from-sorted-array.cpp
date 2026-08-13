class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n =nums.size();
        int j=1;
        int i =0;
        while(j<n){
            if(nums[i]!=nums[j]){
            i++;//comparing if next number is same or different
            nums[i]=nums[j];//if not then store into i and again compare
            }
             j++; // increament  j pointer so that aage ka bhi check pae
        }
      
       return i+1;// this will return the number of times numbers are different
    }

};