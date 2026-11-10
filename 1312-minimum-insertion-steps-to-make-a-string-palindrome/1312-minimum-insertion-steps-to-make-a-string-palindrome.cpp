class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());

        vector<int>prev(n+1, 0);

        for(int i=1; i<=n; i++) {
            vector<int> curr(n+1, 0);
            for(int j=1; j<=n; j++) {
                if(s[i-1] == s2[j-1]) {
                    curr[j] = 1 + prev[j-1];
                } else {
                    curr[j] = max(curr[j-1], prev[j]);
                }
            }
            prev = curr;
        }

        return n-prev[n];

    }
};