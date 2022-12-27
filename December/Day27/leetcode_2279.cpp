class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
      int n = capacity.size();
      vector<int>ans(n);
      for(int i=0;i<n;i++)
      {
          ans[i] = capacity[i]-rocks[i];
      } 
      sort(ans.begin(),ans.end());
      int count = 0;
      for(auto x:ans){
          if(x==0)
          {
              count++;
          }
          else
          {
              if(additionalRocks>0 && additionalRocks>=x)
              {
                  additionalRocks -= x;
                  count++;
              }
          }
      }
      return count;
    }
};
