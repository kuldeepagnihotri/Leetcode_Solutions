class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int ans =0;
      int i =0;
      int j =0;
      set<char> st;
      while(j<s.length()){
        // if no dupliactes found then we will add that value in answer
       if(st.find(s[j])==st.end()){
        st.insert(s[j]);
        j++;
        ans=max(ans,j-i);
       }
       else{
        // if dupliactes found then shrink the window from the left and again update answer
        st.erase(s[i]);
        i++;
       }
      }  
      return ans ;
    }
};