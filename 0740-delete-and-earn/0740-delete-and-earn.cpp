class Solution {
public:
    int maxiMumPoints(int n, vector<int> &points, vector<int>& dp) {
        if(n == 0)
        return points[0];

        if(n==1)
        return max(points[0], points[1]);

        if(dp[n] != -1)
        return dp[n];

        return dp[n] = max(points[n] + maxiMumPoints(n-2, points, dp), maxiMumPoints(n-1, points, dp));

    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
        return 0;

        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> points(maxi+1,0);
        vector<int> dp(maxi+1, 0);

        for(int num: nums) {
            points[num] += num;
        }

        dp[0] = points[0];
        dp[1] = max(points[0], points[1]);

        for(int i=2; i<=maxi; i++) {
            dp[i] = max(points[i] + dp[i-2], dp[i-1]);
        }

        return dp[maxi];

        //return maxiMumPoints(*max_element(nums.begin(), nums.end()), points, dp); 
    }
};