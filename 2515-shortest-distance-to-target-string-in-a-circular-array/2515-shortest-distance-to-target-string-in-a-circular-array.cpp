class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDistance= INT_MAX;
        for(int i =0;i<words.size();i++){
            if(words[i]==target){
                int forward=(i-startIndex +n)%n;
                int backward=(startIndex-i +n)%n;
                minDistance=min(minDistance,min(forward,backward));
            }
        }
        return minDistance == INT_MAX ? -1 : minDistance;
    }
};