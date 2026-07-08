class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;

        // Count frequency
        for (auto num : nums) {
            mp[num]++;
        }

        
        sort(nums.begin(), nums.end(), [&](int n1, int n2) {
            if (mp[n1] != mp[n2]) {
                return mp[n1] < mp[n2];   // Lower frequency first
            }
            return n1 > n2;               // If same frequency, larger number first
        });

        return nums;
    }
};