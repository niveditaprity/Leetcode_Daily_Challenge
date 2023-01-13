class Solution {
public:
  void dfs(vector<vector<int>>&adj,vector<int>&dist,string&s,int curr,int &ans)
  {
   dist[curr] = 1;
   for(int& x : adj[curr])
   {
       dfs(adj,dist,s,x,ans);
       if(s[x] != s[curr] )
       {
         ans = max(ans,dist[curr]+dist[x]);
         dist[curr] = max(dist[curr],dist[x]+1);
       }
   }
  }
    int longestPath(vector<int>& parent, string s) {
    int n = parent.size();
    vector<vector<int>>adj(n);
    vector<int>dist(n);
    for(int i = 1;i<n;i++)
    {
        adj[parent[i]].push_back(i);
    }
     int ans = 1;
     dfs(adj,dist,s,0,ans);  
     return ans;
    }
};
