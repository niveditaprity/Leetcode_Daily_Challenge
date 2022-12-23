class Solution {
public:
   int ans;
    int find(int i,int n, bool flag, vector<int>& prices,vector<vector<int>>&dp)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[flag][i] != -1)
        {
            return dp[flag][i];
        }
        if(flag == false)
        {
            int buy = (0-prices[i]) + find(i+1,n,true,prices,dp);
            int notbuy = 0 + find(i+1,n,false,prices,dp);
            ans = max(buy,notbuy);
        }
        else
        {
           int sell = prices[i] + find(i+2,n,false,prices,dp);
           int notsell = find(i+1,n,true,prices,dp);
           ans = max(sell,notsell);
        }
        dp[flag][i] = ans;
        return ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(2,vector<int>(n,-1));
        return find(0,n,false,prices,dp);

    }
};
