class Solution {
public:
    int maxCherry(int r1, int c1, int r2, int n, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int c2 = (r1+c1) - r2;

        if(r1>=n || r2>=n || c1>=n || c2>=n)
        return INT_MIN;

        if(grid[r1][c1] == -1 || grid[r2][c2] == -1)
        return INT_MIN;

        if(r1 == n-1 && c1 == n-1)
        return grid[r1][c1];

        if(dp[r1][c1][r2] != -1)
        return dp[r1][c1][r2];

        int cherry = grid[r1][c1];

        if(r1!=r2 || c1!=c2)
        cherry += grid[r2][c2];

        int DD = maxCherry(r1+1, c1, r2+1,n, grid, dp);
        int DR = maxCherry(r1+1, c1, r2, n, grid, dp);
        int RD = maxCherry(r1, c1+1, r2+1, n, grid, dp);
        int RR = maxCherry(r1, c1+1, r2, n, grid, dp);

        int pick = max({DD, DR, RD, RR});

        if(pick == INT_MIN)
        return dp[r1][c1][r2] = INT_MIN;

        return dp[r1][c1][r2] = cherry+pick;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(n+1, INT_MIN)));
        dp[n-1][n-1][n-1] = grid[n-1][n-1];

        for(int r1=n-1; r1>=0; r1--) {
            for(int c1=n-1; c1>=0; c1--) {
                for(int r2=n-1; r2>=0; r2--) {
                    if(r1 == n-1 && c1 == n-1)
                    continue;

                    int c2 = (r1+c1)-r2;

                    if(c2 < 0 || c2 >= n)
                    continue;


                    if(grid[r1][c1] == -1 || grid[r2][c2] == -1)
                    continue;

                    int cherry = grid[r1][c1];

                    if(r1!=r2 || c1!=c2)
                    cherry+=grid[r2][c2];

                    int DD = dp[r1+1][c1][r2+1];
                    int DR = dp[r1+1][c1][r2]; 
                    int RD = dp[r1][c1+1][r2+1]; 
                    int RR = dp[r1][c1+1][r2]; 

                    int pick = max({DD, DR, RD, RR});

                    if(pick == INT_MIN)
                    continue;

                    dp[r1][c1][r2] = cherry+pick;

                }
            }
        }

        return max(0, dp[0][0][0]);
        // int ans = maxCherry(0, 0, 0,n, grid, dp);

        // return max(0, ans);
    }
};