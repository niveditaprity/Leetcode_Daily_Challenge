class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      int count = 0;
      unordered_map<int,int>mp;
      int sum = 0;
      mp[0]++;
      for(auto x:nums)
      {
        sum+=x;
        if(mp[(sum%k+k)%k]>0)
        {
        count+=mp[(sum%k+k)%k];
        }
        mp[(sum%k+k)%k]++;
      }
      return count;  
    }
};
