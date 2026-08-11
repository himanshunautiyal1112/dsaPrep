class Solution {
public:
    int totalWays(int index, int n, string s, vector<int>& dp) {
        if(index == n)
        return 1;

        if(s[index] == '0')
        return 0;

        if(dp[index] != -1)
        return dp[index];

        int ways = totalWays(index+1, n, s, dp);

        if(index+1<n) {
            if(s[index] == '1' || (s[index] == '2' && s[index+1] <= '6'))
            ways+=totalWays(index+2, n, s, dp);
        }

        return dp[index] = ways;

        
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        if(s[0] == '0')
        return 0;

        dp[n] = 1;
        for(int i=n-1; i>=0; i--) {
            if(s[i] == '0'){
                dp[i] = 0;
                continue;
            }

            int ways = dp[i+1];

            if(i+1 < n) {
                if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
                ways += dp[i+2];
            }
            dp[i] = ways;
        }
        return dp[0];
        //return totalWays(0, n, s, dp);
    }
};