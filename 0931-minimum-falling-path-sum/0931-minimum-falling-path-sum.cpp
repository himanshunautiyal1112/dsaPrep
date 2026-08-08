class Solution {
public:
    int minPath(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(j < 0 || j >= n)
            return INT_MAX;

        if(i == n-1)
            return matrix[i][j];

        if(dp[i][j] != INT_MAX)
        return dp[i][j];

        return dp[i][j] =  matrix[i][j] +
            min({
                minPath(i+1, j-1, n, matrix, dp),
                minPath(i+1, j, n, matrix, dp),
                minPath(i+1, j+1, n, matrix, dp)
            });
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));

        int result = INT_MAX;
        for(int j=0; j<n; j++) {
            int ans = minPath(0, j, n, matrix, dp);
            result = min(ans, result);
        }
        return result;
    }
};