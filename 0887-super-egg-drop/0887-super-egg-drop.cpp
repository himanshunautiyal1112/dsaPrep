class Solution {
public:
    int findTotalMoves(int eggs, int moves, vector<vector<int>>& dp) {
        if(eggs == 0 || moves == 0)
        return 0;

        if(eggs == 1)
        return moves;

        if(dp[eggs][moves] != -1)
        return dp[eggs][moves];

        return dp[eggs][moves] = 1+findTotalMoves(eggs-1, moves-1, dp)+findTotalMoves(eggs, moves-1, dp);
    }
    int superEggDrop(int k, int n) {
        int moves = 0;
        vector<vector<int>> dp(k+1, vector<int>(n+1, 0));

        for(int i=0; i<=n; i++)
        dp[1][i] = i;

        for(int moves=1; moves<=n; moves++) {
            for(int eggs=2; eggs<=k; eggs++) {
                dp[eggs][moves] = 1 + dp[eggs-1][moves-1] + dp[eggs][moves-1];
            }
            if(dp[k][moves] >= n) 
            return moves;
        }

        // while(findTotalMoves(k, moves, dp)<n){
        //     moves++;
        // }
        // return moves;
        return n;
    }
};