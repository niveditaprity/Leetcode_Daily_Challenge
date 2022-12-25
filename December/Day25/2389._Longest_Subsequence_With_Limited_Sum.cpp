class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        vector<int> ans;
        
        for(auto tar : queries)
        {
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if(nums[i] <= tar)
                {
                    tar = tar-nums[i];
                    cnt++;
                }
                else
                    break;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
