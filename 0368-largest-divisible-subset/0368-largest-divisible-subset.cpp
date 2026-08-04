class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> LDS(n, 1);
        vector<int> parent(n, -1);
        int maxLen = 1, index = 0;

        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i]%nums[j] == 0) {
                    if(LDS[i] < LDS[j]+1) {
                        LDS[i] = 1+LDS[j];
                        parent[i] = j;
                    }
                }
            }
            if(LDS[i] > maxLen) {
                maxLen = LDS[i];
                index = i;
            }
        }
        vector<int> ans;

        while(index != -1) {
            ans.push_back(nums[index]);
            index = parent[index];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

};