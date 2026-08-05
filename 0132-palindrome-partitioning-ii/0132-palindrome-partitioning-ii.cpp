class Solution {
public:
    int minCut(string s) {
      int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, 0));

        for(int i=0; i<n; i++)
        dp[i][i] = 1;

        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j = i+len-1;

                if(s[i]==s[j]&&(len==2 || dp[i+1][j-1])){
                    dp[i][j] = 1;
                }
            }
        } 
        vector<int> cuts(n, INT_MAX);
        cuts[n-1] = 0;

        for(int i=n-2; i>=0; i--) {
            for(int j=i; j<n; j++) {
                if(dp[i][j]) {
                    if(j==n-1)
                    cuts[i] = 0;
                    else 
                    cuts[i] = min(cuts[i], 1+cuts[j+1]);
                }
            }
        }
        return cuts[0];
    }
};