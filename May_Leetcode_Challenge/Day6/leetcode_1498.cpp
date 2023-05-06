class Solution {
public:
    int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        long long res = 0;
        vector<int>power(n);
        power[0] = 1;
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % MOD;
        }
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                r--;
            } else {
                int len = r - l;
                res = (res + power[len] % MOD);
                l++;
            }
        }
        return res;
    }
};
