class Solution {
public:
    int minimumCost(int index, vector<int>& cost, vector<int>& dp) {
        if(index <= 1)
        return 0;
        if(dp[index] != -1)
        return dp[index];

        int oneStep = cost[index-1] + minimumCost(index-1, cost, dp);
        int twoStep = INT_MAX;

        if(index >= 2) {
           twoStep = cost[index-2] + minimumCost(index-2, cost, dp);
        }

        return dp[index] = min(oneStep, twoStep);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0);
        
        for(int i=2; i<=n; i++) {
            int oneStep = cost[i-1] + dp[i-1];
            int twoStep = INT_MAX;
            if(i>=2) {
                twoStep = cost[i-2] + dp[i-2];
            }
            dp[i] = min(oneStep, twoStep);
        }
        return dp[n];
        //return minimumCost(n, cost, dp);
    }
};