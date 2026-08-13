class Solution {
public:
    bool isPalindrome(int x) {
        // one more method of palindrome number is to change the integer to string then reverse the string and checks
        string s=to_string(x);
        string t=s;
        reverse(s.begin(),s.end());
       return s==t;
        
    }
};