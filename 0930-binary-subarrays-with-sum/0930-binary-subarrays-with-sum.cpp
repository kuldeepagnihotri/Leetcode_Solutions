/*class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i =0;
        int j =0;
        int count = 0;
        int sum = 0;
        while ( j < nums .size()){
            sum+=nums[j];


            while(sum>goal){
                sum=sum-nums[i];
                i++;
            }
            if(sum==goal)count++;
            j++;
        }
        return count ;
    }
};  this code is correct but not optimised hash map use hoga */
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for(int x : nums) {
            sum += x;

            if(mp.count(sum - goal))
                count += mp[sum - goal];

            mp[sum]++;
        }

        return count;
    }
};
