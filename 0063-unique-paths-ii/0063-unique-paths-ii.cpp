class Solution {
public:
    int totalPathWithObt(int i, int j, int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if(i == row-1 && j==col-1)
        return 1;

        if(i>=row || j>=col)
        return 0;

        if(obstacleGrid[i][j] == 1)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        return dp[i][j] = totalPathWithObt(i, j+1, row, col, obstacleGrid, dp) + totalPathWithObt(i+1, j, row, col, obstacleGrid, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1] == 1)
        return 0;

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return totalPathWithObt(0, 0, n, m, obstacleGrid, dp);
    }
};