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

        for(int i=n-2; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                int minChoice = matrix[i+1][j];
                if(j>0) minChoice = min(minChoice, matrix[i+1][j-1]);
                if(j<n-1) minChoice = min(minChoice, matrix[i+1][j+1]);

                matrix[i][j] += minChoice;
            }
        }
        int result = INT_MAX;
        
        for(int i=0; i<n; i++) {
            result = min(result, matrix[0][i]);
        }
        return result;
        //dp

        // vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));

        // for(int j=0; j<n; j++)
        // dp[n-1][j] = matrix[n-1][j];

        // for(int i=n-2; i>=0; i--) {
        //     for(int j=n-1; j>=0; j--) {
        //         if(j==0)
        //         dp[i][j] = matrix[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
        //         else if(j==n-1)
        //         dp[i][j] = matrix[i][j] + min(dp[i+1][j-1], dp[i+1][j]);
        //         else 
        //         dp[i][j] = matrix[i][j] + min({dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]});
        //     }
        // }
        // int result = INT_MAX;
        // for(int i=0; i<n; i++) {
        //     result = min(result, dp[0][i]);
        // }
        // return result;
    }
};