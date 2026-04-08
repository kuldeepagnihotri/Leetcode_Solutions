class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0) return 0;
        vector<int> preffixMax(n), suffixMax(n);

        //preffix sum
        preffixMax[0] = height[0];
        for(int i=1;i<n;i++){
            preffixMax[i] = max(preffixMax[i-1],height[i]);
        }
        //suffix sum
        suffixMax[n-1] = height[n-1];
        for(int i=n-2; i>=0;i--){
         suffixMax[i] = max( suffixMax[i+1],height[i]); 
        }

        // water calculation
        int total = 0;
        for (int i =0 ; i < n ;i++){
        int leftMax=preffixMax[i];
        int rightMax=suffixMax[i];

        total += min(leftMax, rightMax) - height[i];
      }

        return total;
    }
};