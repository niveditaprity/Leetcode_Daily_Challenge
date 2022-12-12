class Solution {
public:
    int count(int n,int step,vector<int>&dp)
    {
        if(step>n)
        {
            return 0;
        }
        if(step == n)
        {
            return 1;
        }
        if(dp[step]!=-1)
        {
            return dp[step];
        }
        
        dp[step] = count(n,step+1,dp) + count(n,step+2,dp);
        return dp[step];
    }
    int climbStairs(int n) {
       vector<int>dp(n+1,-1);
       return count(n,0,dp);  
    }
};
