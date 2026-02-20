class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>degree(n+2,0);

        for(auto&e : edges){
        degree[e[0]]++;
        degree[e[1]]++;
        }
        for(int i=1;i<=n+1;i++){
            if(degree[i]==n)
                return i;
        }
            return -1;
        
        
    }
};