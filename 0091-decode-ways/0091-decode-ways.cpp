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
        vector<int> dp(n+1, -1);
        return totalWays(0, n, s, dp);
    }
};