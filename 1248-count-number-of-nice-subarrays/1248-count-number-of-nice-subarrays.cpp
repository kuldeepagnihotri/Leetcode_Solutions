/*class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
    int i=0;
    int j =0;
    int count =0; 
    int sum=0;
    while(j<nums.size()){
        sum+= (nums[j]%2);
        while(sum>k){
            sum-=nums[i]%2;
            i++;
        }
        count = count + (j-i+1);
        j++;
    }
    return count;
    }
}; again the solution is correct but not optimised so hash map will be used*/
class Solution {
public:

    int atMost(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int count = 0;
        int sum = 0;

        while (j < nums.size()) {
            sum += (nums[j] % 2);

            while (sum > k) {
                sum -= (nums[i] % 2);
                i++;
            }

            count += (j - i + 1);
            j++;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};