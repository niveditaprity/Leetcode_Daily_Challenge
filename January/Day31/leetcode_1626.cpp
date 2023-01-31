class Solution {
public:
    vector<vector<int>>dp;
     int solve(int i,int j,int n,vector<pair<int,int>>&players)
     {
        if(i == n)
        {
            return 0;
        }
        if(dp[i][j+1]!= -1)
        {
            return dp[i][j+1];
        }
        int notake = solve(i+1,j,n,players);
        if(j == -1 or players[j].second<= players[i].second)
        {
         int take = players[i].second + solve(i+1,i,n,players);
         return dp[i][j+1] =  max(take,notake);
        }
        return dp[i][j+1] = notake;

     }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        dp.resize(1002,vector<int>(1002,-1));
        vector<pair<int,int>>players;
        int n = scores.size();
        
        for(int i = 0;i<n;i++)
        {
          players.push_back({ages[i],scores[i]});  
        }
        sort(players.begin(),players.end());
        return solve(0,-1,n,players);

    }
};
