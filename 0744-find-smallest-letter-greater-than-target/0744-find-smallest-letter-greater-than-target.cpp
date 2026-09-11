class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int low = 0, high = n - 1;
        char ans = '#';

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (letters[mid] > target) {
                ans = letters[mid];
                high = mid - 1;   // left me aur chhota dhoondo
            } else {
                low = mid + 1;
            }
        }

        // circular condition
        if (ans == '#') return letters[0];

        return ans;
    }
};
