class Solution {
public:
    int findMin(int index, string &s, unordered_set<string> &word, vector<int>&dp) {
        if(index == s.size())
        return 0;

        if(dp[index] != -1)
        return dp[index];

        int ans = 1 + findMin(index+1, s, word, dp);

        for(int j=index; j<s.size(); j++) {
            if(word.count(s.substr(index, j-index+1))) {
                ans = min(ans, findMin(j+1, s, word, dp));
            }
        }

        return dp[index] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> word(dictionary.begin(), dictionary.end());

        vector<int>dp(s.size()+1, 0);

        for(int i = s.size()-1; i>=0; i--) {
            int ans = 1+dp[i+1];
            for(int j=i; j<s.size(); j++) {
                if(word.count(s.substr(i, j-i+1))) {
                    ans = min(ans, dp[j+1]);
                }
            }
            dp[i] = ans;
        }
        return dp[0];
        //return findMin(0, s, word, dp);
    }
};