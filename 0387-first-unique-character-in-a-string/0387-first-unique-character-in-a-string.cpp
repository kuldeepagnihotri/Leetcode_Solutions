class Solution {
public:
    int firstUniqChar(string s) {
        // brute force
        int n = s.length();
        for(int i =0;i<n;i++){
            bool unique=true;
        
        for(int j =0;j<n;j++){
            if(i!=j && s[i]==s[j]){
                unique=false;
                break;
            }
        }
        if(unique) return i;
        
    }
    return -1;
    }
};