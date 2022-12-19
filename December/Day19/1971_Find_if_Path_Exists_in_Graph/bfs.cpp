class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)  
    {
     vector<int>graph[n];
     vector<bool>visited(n,false);
     queue<int>q;
     for(auto x : edges)
     {
         graph[x[0]].push_back(x[1]);
         graph[x[1]].push_back(x[0]);
     }
     q.push(source);
     while(!q.empty())
     {
         int x = q.front();
         q.pop();
         if(x == destination )
         {
             return true;
         }
         for(auto ele : graph[x])
         {
             if(!visited[ele])
             {
                 q.push(ele);
                 visited[ele] = true;
             }
         }
         
     } 
     return false;
    }
};
