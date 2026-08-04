class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int totalSubstr = 0;

        vector<vector<bool>> dp(n, vector<bool>(n, 0));

        for(int i=0; i<n; i++)
        dp[i][i] = 1;

        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j = i+len-1;

                if(s[i]==s[j]&&(len==2 || dp[i+1][j-1])){
                    dp[i][j] = 1;
                    totalSubstr++;
                }
            }
        }
        return totalSubstr+s.size();
    }
};