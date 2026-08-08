class Solution {
public:
    int reverse(int x) {
        long long n = x;
        bool negative =n<0;
        if(negative)
        n=-n;
        string s = to_string(n);
        std::reverse(s.begin(),s.end());

        long long y = stoll(s);
        if(negative)
        y=-y;
        if(y>INT_MAX || y<INT_MIN) return 0;
    
        return(int)y;
        
    }
};