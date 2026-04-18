

class Solution {
public:
    int mirrorDistance(int n) {
        int original = n;// keeping the original number safe 
        int rev =0;
        while(n>0){
            int digit = n%10;
            rev = rev* 10 +digit;
            n=n/10;
        }
        return abs(original-rev);// get the absolute value
    }
};