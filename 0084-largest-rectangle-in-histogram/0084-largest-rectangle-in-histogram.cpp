class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // ---- Finding NSL (Nearest Smaller to Left) ----
        vector<int> left(n);
        stack<pair<int,int>> s1; // {height, index}

        for(int i = 0; i < n; i++) {
            while(!s1.empty() && s1.top().first >= heights[i])
                s1.pop();

            if(s1.empty())
                left[i] = -1;
            else
                left[i] = s1.top().second;

            s1.push({heights[i], i});
        }

        // ---- Finding NSR (Nearest Smaller to Right) ----
        vector<int> right(n);
        stack<pair<int,int>> s2;

        for(int i = n-1; i >= 0; i--) {
            while(!s2.empty() && s2.top().first >= heights[i])
                s2.pop();

            if(s2.empty())
                right[i] = n;
            else
                right[i] = s2.top().second;

            s2.push({heights[i], i});
        }

        // ---- Calculate Maximum Area ----
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
