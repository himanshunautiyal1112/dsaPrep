class Solution {
public:
    int findMinCost(int start, int end, vector<int>&cuts, vector<vector<int>>& dp) {
        if(start+1 == end)
        return 0;

        if(dp[start][end] != -1)
        return dp[start][end];

        int result = INT_MAX;
        for(int k=start+1; k<end; k++) {
            int ans = cuts[end]-cuts[start] + findMinCost(start, k, cuts, dp) + findMinCost(k, end, cuts, dp);
            result = min(result, ans);
        }

        return dp[start][end] = result;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), 0));
        
        for(int end=1; end<cuts.size(); end++) {
            for(int start=end-2; start>=0; start--) {
                int result = INT_MAX;
                for(int k=start+1; k<end; k++) {
                    int ans = cuts[end]-cuts[start] + dp[start][k] + dp[k][end];
                    result = min(result, ans);
                }
                dp[start][end] = result;
            }
        }
        return dp[0][cuts.size()-1];
       // return findMinCost(0, cuts.size()-1, cuts, dp);
    }
};