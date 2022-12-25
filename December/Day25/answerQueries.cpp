class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size();
    int m = queries.size();
    sort(nums.begin(),nums.end());
    vector<int>psum(n);
    vector<int>ans(m);
    psum[0]=nums[0];
    for(int i=1;i<n;i++)
    {
    psum[i]=psum[i-1]+nums[i];
    }
    for(int i = 0;i<m; i++)
    {
      int upper = upper_bound(psum.begin(), psum.end(), queries[i]) - psum.begin();
      ans[i] = upper;

    }

    return ans;
    }
};
