class Solution {
public:
    int totalIncreasingPath(int i, int j, int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {

        if(dp[i][j] != -1)
        return dp[i][j];

        long long result = 1;

        // up down left right
        if(i>0 && grid[i-1][j] > grid[i][j]) {
            result+=totalIncreasingPath(i-1, j, row, col, grid, dp);
        }
        if(i<row-1 && grid[i+1][j] > grid[i][j]) {
            result+=totalIncreasingPath(i+1, j, row, col, grid, dp);
        }
        if(j>0 && grid[i][j-1] > grid[i][j]) {
            result+= totalIncreasingPath(i, j-1, row, col, grid, dp);
        }
        if(j<col-1 && grid[i][j+1] > grid[i][j]) {
            result+=totalIncreasingPath(i, j+1, row, col, grid, dp);
        }

        return dp[i][j] = result%1000000007;
    }

    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long totalPath = 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                totalPath += totalIncreasingPath(i, j, m, n, grid, dp);
                totalPath %= 1000000007;
            }
        }
        return totalPath;
    }
};