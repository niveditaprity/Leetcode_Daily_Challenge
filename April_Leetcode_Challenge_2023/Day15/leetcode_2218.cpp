//Recursive 
class Solution {
public:
    int findMaxValueOfCoins(vector<vector<int>>& piles,int n, int k)
    {
       if(n< 0 || k == 0) 
       {
           return 0;
       }
       int maxPick = findMaxValueOfCoins(piles,n-1,k);
       int totalPickedValue = 0;
       int currPileSize = piles[n].size();
       int maxPile = min(k,currPileSize);
       for(int i = 0; i<maxPile; i++)
       {
          totalPickedValue+= piles[n][i];
          maxPick  = max(maxPick ,totalPickedValue+findMaxValueOfCoins(piles,n-1,k-i-1));
       }
       return maxPick;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
       int n = piles.size();
       return findMaxValueOfCoins(piles, n-1, k);

    }
};

//Memoize


class Solution {
public:
    int findMaxValueOfCoins(vector<vector<int>>& piles,int n, int k, vector<vector<int>>&dp)
    {
       if(n< 0 || k == 0) 
       {
           return 0;
       }
       if(dp[n][k]!=-1)
       {
           return dp[n][k];
       }
       int maxPick = findMaxValueOfCoins(piles,n-1,k,dp);
       int totalPickedValue = 0;
       int currPileSize = piles[n].size();
       int maxPile = min(k,currPileSize);
       for(int i = 0; i<maxPile; i++)
       {
          totalPickedValue+= piles[n][i];
          maxPick = max(maxPick  ,totalPickedValue+findMaxValueOfCoins(piles,n-1,k-i-1,dp));
       }
       dp[n][k] = maxPick;
       return dp[n][k];
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
       int n = piles.size();
       vector<vector<int>>dp(n,vector<int>(k+1,-1));
       return findMaxValueOfCoins(piles, n-1, k, dp);

    }
};
