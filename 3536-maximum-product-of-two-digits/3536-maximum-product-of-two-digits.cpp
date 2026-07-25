class Solution {
public:
    int maxProduct(int n) {
      vector<int>digits;
      int product=0;
        while(n>0){
        digits.push_back(n%10);
        n/=10;
      for(int i = 0;i<digits.size();i++){
        for(int j = i+1;j<digits.size();j++){
       product = max(product, digits[i] * digits[j]);
        }
      }
    }
     return product;
    }
};