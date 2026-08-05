class Solution {
public:
    int maxCoin(int start, int end, vector<int> &nums, vector<vector<int>>& dp) {
        if(start+1 == end)
        return 0;

        if(dp[start][end] != -1)
        return dp[start][end];

        int result = INT_MIN;
        for(int k=start+1; k<end; k++) {
            int ans = nums[start] * nums[k] * nums[end] + maxCoin(start, k, nums, dp) + maxCoin(k, end, nums, dp);
            result = max(result, ans);
        }
        return dp[start][end] = result;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        arr.push_back(1);
        for(int i=0; i<n; i++) {
            arr.push_back(nums[i]);
        }
        arr.push_back(1);
        vector<vector<int>> dp(n, vector<int>(n+2, -1));

        return maxCoin(0, n+1, arr, dp);
    }
};