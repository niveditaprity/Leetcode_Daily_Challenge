//Recursion
class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j , int n1, int n2)
    {
        if(i>n1 || j>n2)
        {
            return 0;
        }
        if(nums1[i] == nums2[j])
        {
            return 1 + solve(nums1, nums2, i+1, j+1, n1, n2);
        }
        else
        {
            return max(solve(nums1, nums2, i+1, j, n1, n2),solve(nums1, nums2, i, j+1, n1, n2));
        }
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
      return solve(nums1,nums2,0,0,nums1.size()-1,nums2.size()-1); 
    }
};


//Memoization
class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j , int n1, int n2,vector<vector<int>>&dp)
    {
        if(i>n1 || j>n2)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(nums1[i] == nums2[j])
        {
            dp[i][j] =  1 + solve(nums1, nums2, i+1, j+1, n1, n2, dp);
            return dp[i][j];
        }
        else
        {
            dp[i][j]  = max(solve(nums1, nums2, i+1, j, n1, n2, dp),solve(nums1, nums2, i, j+1, n1, n2, dp));
            return dp[i][j];
        }
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
      int n1 = nums1.size(), n2 =  nums2.size();
      vector<vector<int>>dp(n1, vector<int>(n2,-1));
      return solve(nums1, nums2, 0, 0, n1-1, n2-1, dp); 
    }
};
// dp

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
      int n1 = nums1.size(), n2 =  nums2.size();
      vector<vector<int>>dp(n1+1, vector<int>(n2+1,0));

      for(int i = 1; i<=n1; i++)
      {
          for(int j = 1; j<=n2; j++)
          {
              if(nums1[i-1] == nums2[j-1] )
              {
                  dp[i][j] = 1 + dp[i-1][j-1];
              }
              else
              {
                  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
              }
          }
      }
      return dp[n1][n2];

      
    }
};
