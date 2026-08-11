class Solution {
public:
    long long tribonacci(int n) {
         vector<int> dp(4, 0);
        if(n == 0)
        return 0;

        if(n==1 || n==2)
        return 1;

        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        for(int i=4; i<=n; i++) {
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = dp[3];
            dp[3] = dp[2] + dp[1] + dp[0];
            //dp[3] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[3];
    }
};