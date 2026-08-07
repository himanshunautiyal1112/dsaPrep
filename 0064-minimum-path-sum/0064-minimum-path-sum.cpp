class Solution {
public:
    int minimumPathSum(int i, int j, int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i == row-1 && j == col-1)
        return grid[i][j];

        if(i >= row || j >= col)
        return 1e9;

        if(dp[i][j] != -1)
        return dp[i][j];

        return dp[i][j] = grid[i][j] + min(minimumPathSum(i, j+1, row, col, grid, dp), minimumPathSum(i+1, j, row, col, grid, dp));

    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        dp[n-1][m-1] = grid[n-1][m-1];

        for(int row=n-1; row>=0; row--) {
            for(int col=m-1; col>=0; col--) {
                if(row == n-1 && col == m-1)
                dp[row][col] = grid[row][col];
                else if(row==n-1)
                dp[row][col] = grid[row][col]+dp[row][col+1];
                else if(col == m-1)
                dp[row][col] = grid[row][col] + dp[row+1][col];
                else 
                dp[row][col] = grid[row][col] + min(dp[row][col+1], dp[row+1][col]);
            }
        }
        return dp[0][0];
        //return minimumPathSum(0, 0, n, m, grid, dp);
    }
};