class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int read =0;
        int write=0;
        while(read < n){
        char ch = chars[read];
        int count =0;
        // Find complete group
        while(read<n && chars[read]==ch){
            count++;
            read++;
        }
        //write character
        chars[write++]=ch;
        // write frequency
        if(count>1){
            string freq=to_string(count);

            for(char c : freq){
                chars[write++]=c;
            }
        }
        }
        return write;
    }
};