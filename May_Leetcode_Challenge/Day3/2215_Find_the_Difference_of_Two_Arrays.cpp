class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
      vector<vector<int>>ans(2);
      unordered_set<int>s1(nums1.begin(),nums1.end());
      unordered_set<int>s2(nums2.begin(),nums2.end());

      for(auto ele : s1)
      {
          if(!s2.count(ele))
          {
            ans[0].push_back(ele);
          }
      }
      for(auto ele : s2)
      {
          if(!s1.count(ele))
          {
            ans[1].push_back(ele);
          }
      }
      
      return ans;

    }
};
