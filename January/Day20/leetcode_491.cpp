class Solution {
public:
    map<vector<int>,int>mp;
    void solve(vector<vector<int>>&ans, vector<int>&temp,vector<int>& nums,int i)
    {
        if(i>nums.size())
        {
              return;
        }
        if(temp.size()>=2)
        {
          if(mp[temp]>=1)
          {
            return;  
          }
          mp[temp]++;
          ans.push_back(temp);
        }
        for(int j = i ;j<nums.size();j++ )
        {
            if(temp.size()>=1 && nums[j]< temp[temp.size()-1])
            {
                continue;
            }
            temp.push_back(nums[j]);
            solve(ans,temp,nums,j+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,temp,nums,0);
        return ans;
    }
};
