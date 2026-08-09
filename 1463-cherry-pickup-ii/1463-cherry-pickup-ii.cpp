class Solution {
public:
    int maxCherryPic(int r1, int c1, int c2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int r2 = r1;
        if(c1>=m || c1<0 || c2>=m || c2<0)
        return INT_MIN;

        if(r1==n-1) {
            if(c1 == c2) {
                return grid[r1][c1];
            }
            return grid[r1][c1]+grid[r1][c2];
        }

        if(dp[r1][c1][c2] != -1)
        return dp[r1][c1][c2];

        int robot1Cherry = grid[r1][c1];

        if(c1!=c2)
        robot1Cherry += grid[r1][c2];

        int DD = maxCherryPic(r1+1, c1, c2, n, m, grid, dp);
        int DRd = maxCherryPic(r1+1, c1, c2+1, n, m, grid, dp);
        int RdD = maxCherryPic(r1+1, c1+1, c2, n, m, grid, dp);
        int DLd = maxCherryPic(r1+1, c1, c2-1, n, m, grid, dp);
        int LdD = maxCherryPic(r1+1, c1-1, c2, n, m, grid, dp);
        int LdRd = maxCherryPic(r1+1, c1-1, c2+1, n, m, grid, dp);
        int RdLd = maxCherryPic(r1+1, c1+1, c2-1, n, m, grid, dp);
        int LL = maxCherryPic(r1+1, c1-1, c2-1, n, m, grid, dp);
        int RR = maxCherryPic(r1+1, c1+1, c2+1, n, m, grid, dp);

        int pick = max({DD, DRd, RdD, DLd, LdD, LdRd, RdLd, LL, RR});

        if(pick == INT_MIN)
        return dp[r1][c1][c2] = INT_MIN;

        return dp[r1][c1][c2] = robot1Cherry+pick;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m+1, vector<int>(m+1, -1)));

        int ans = maxCherryPic(0, 0, m-1, n, m, grid, dp);
        return max(0, ans);
    }
};