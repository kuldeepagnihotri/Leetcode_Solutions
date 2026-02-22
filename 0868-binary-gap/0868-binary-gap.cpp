class Solution {
public:
    int binaryGap(int n) {
        
        // Step 1: Convert decimal to binary string
        string binary = "";
        while(n > 0){
            binary = char('0' + (n % 2)) + binary;
            n = n / 2;
        }

        int maxCount = 0;
        int lastIndex = -1;

        // Step 2: Find maximum distance between consecutive 1s
        for(int i = 0; i < binary.length(); i++){
            if(binary[i] == '1'){
                if(lastIndex != -1){
                    maxCount = max(maxCount, i - lastIndex);
                }
                lastIndex = i;
            }
        }

        return maxCount;
    }
};