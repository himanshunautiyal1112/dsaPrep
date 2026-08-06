class Solution {
public:
    int totalPathWithObt(int i, int j, int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if(i >= row || j >= col)
        return 0;

        if(obstacleGrid[i][j] == 1)
        return 0;

        if(i == row-1 && j == col-1)
        return 1;

        if(dp[i][j] != -1)
        return dp[i][j];

        return dp[i][j] = totalPathWithObt(i, j+1, row, col, obstacleGrid, dp) + totalPathWithObt(i+1, j, row, col, obstacleGrid, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1] == 1)
        return 0;

        if(obstacleGrid[0][0] == 1)
        return 0;

        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
        dp[n-1][m-1] = 1;
        
        for(int i = n-1; i >= 0; i--) {

            for(int j = m-1; j >= 0; j--) {

                if(obstacleGrid[i][j] == 1)
                dp[i][j] = 0;

                else if(i == n-1 && j == m-1)
                dp[i][j] = 1;

                else
                dp[i][j] = dp[i][j+1] + dp[i+1][j];
            }
        }
        return dp[0][0];
        //return totalPathWithObt(0, 0, n, m, obstacleGrid, dp);
    }
};