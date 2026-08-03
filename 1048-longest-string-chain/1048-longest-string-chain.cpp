class Solution {
public:
    static bool com(string s1, string s2) {
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), com);
        unordered_map<string, int> dp;
        int maxLen = 1;

        for(auto w: words) {
            dp[w] = 1;
            for(int i=0; i<w.size(); i++) {
                string s = w.substr(0, i) + w.substr(i+1);

                if(dp.count(s)) {
                    dp[w] = max(dp[w], 1+dp[s]);
                }
            }
            maxLen = max(maxLen, dp[w]);
        }

        return maxLen;
    }
};