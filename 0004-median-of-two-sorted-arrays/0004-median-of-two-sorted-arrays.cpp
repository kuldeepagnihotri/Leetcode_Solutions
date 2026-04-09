class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       vector<int> merged;

       // merge both arrays

       for(int i =0;i<nums1.size();i++){
        merged.push_back(nums1[i]);
       }

       for( int j=0;j<nums2.size();j++){
        merged.push_back(nums2[j]);
       }
        //sort krdo
        sort(merged.begin(),merged.end());

        int k = merged.size();
        if(k%2==0){
            return( (merged[(k/2)-1] + merged[k/2]) / 2.0 );
        }
        else{
            return merged[k/2];
        }
        }
    
};
