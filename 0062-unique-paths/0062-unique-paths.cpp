class Solution {
public:
    int totoalPath(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if(i == m-1 && j==n-1)
        return 1;

        if(i>=m || j>=n)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        return dp[i][j] = totoalPath(i, j+1, m, n, dp) + totoalPath(i+1, j, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 1));

        for(int i=m-2; i>=0; i--) {
            for(int j=n-2; j>=0; j--) {
                dp[i][j] = dp[i][j+1] + dp[i+1][j];
            }
        }
        return dp[0][0];
        //return totoalPath(0,0, m, n, dp);
    }
};