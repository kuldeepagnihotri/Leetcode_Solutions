class Solution {
public:

    // Helper function (MAH)
    int MAH(vector<int>& arr) {
        int size = arr.size();
        stack<int> st;
        vector<int> left(size), right(size);

        // NSL (Nearest Smaller to Left)
        for(int i = 0; i < size; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if(st.empty()) left[i] = -1;
            else left[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // NSR (Nearest Smaller to Right)
        for(int i = size - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if(st.empty()) right[i] = size;
            else right[i] = st.top();

            st.push(i);
        }

        int maxArea = 0;

        for(int i = 0; i < size; i++) {
            int width = right[i] - left[i] - 1;
            int area = width * arr[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if(matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> v(n, 0);
        int mx = 0;

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '0')
                    v[j] = 0;
                else
                    v[j] = v[j] + 1;
            }

            mx = max(mx, MAH(v));
        }

        return mx;
    }
};
