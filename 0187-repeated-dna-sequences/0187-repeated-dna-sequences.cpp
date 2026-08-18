class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n =s.length();
        vector<string>ans;
        unordered_map<string,int>mp;
        for(int i =0;i<=n-10;i++){
         string sub= s.substr(i,10);
         mp[sub]++;
         if(mp[sub]==2) ans.push_back(sub);  
        }
        return ans;
    }
};