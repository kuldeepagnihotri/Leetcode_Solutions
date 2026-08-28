class Solution {
public:

    int m, n;

    int dfs(vector<vector<int>>& grid, int i, int j) {

        // Boundary / water
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 1;
        }

        // Already visited
        if(grid[i][j] == -1) {
            return 0;
        }

        // Mark visited
        grid[i][j] = -1;

        int peri = 0;

        peri += dfs(grid, i + 1, j); // down
        peri += dfs(grid, i - 1, j); // up
        peri += dfs(grid, i, j + 1); // right
        peri += dfs(grid, i, j - 1); // left

        return peri;
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    return dfs(grid, i, j);
                }
            }
        }

        return 0;
    }
};