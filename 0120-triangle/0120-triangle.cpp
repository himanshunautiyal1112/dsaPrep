class Solution {
public:
    int minimumSumPath(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(i == n-1)
        return triangle[i][j];

        if(dp[i][j] != -1)
        return dp[i][j];

        return dp[i][j] = triangle[i][j] + min(minimumSumPath(i+1, j, n, triangle, dp), minimumSumPath(i+1, j+1, n, triangle, dp));

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        //vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> prev(n, 0);

        for(int i=0; i<n; i++)
        prev[i] = triangle[n-1][i];

        for(int i=n-2; i>=0; i--) {
            vector<int> curr(n, 0);
            for(int j=i; j>=0; j--) {
                curr[j] = triangle[i][j] + min(prev[j],prev[j+1]);
            }
            prev = curr;
        }
        return prev[0];
        //return minimumSumPath(0, 0, n, triangle, dp);
    }
};