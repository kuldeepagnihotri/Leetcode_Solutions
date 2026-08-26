class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int ones = 0;
        string ans = "";

        for (int right = 0; right < s.size(); right++) {

            if (s[right] == '1')
                ones++;

            while (ones == k) {

                // Remove unnecessary leading zeros
                while (left <= right && s[left] == '0')
                    left++;

                string curr = s.substr(left, right - left + 1);

                // Compare with answer
                if (ans == "" ||
                    curr.size() < ans.size() ||
                    (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }

                // Remove leftmost 1
                if (s[left] == '1')
                    ones--;

                left++;
            }
        }

        return ans;
    }
};