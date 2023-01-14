class Solution {
public:
    char dfs(char curr, unordered_map<char,list<char>>& adj, vector<int>& vis)
    {
        char minChar = curr;
        vis[curr-'a'] = 1;
        
        for(auto child : adj[curr])
        {
            if(!vis[child-'a'])
            {
                vis[child-'a'] = 1;
                char min_from_child = dfs(child, adj, vis);
                
                minChar = min(minChar, min_from_child);
            }
        }
        return minChar;
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        unordered_map<char,list<char>> adj;
        
        for(int i = 0; i < s1.length(); i++)
        {
            char u = s1[i];
            char v = s2[i];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        string ans;
        
        for(int i = 0; i < baseStr.length(); i++)
        {
            vector<int> vis(26,0);
            
            char ch = baseStr[i];
            char minChar = dfs(ch, adj, vis);
            
            ans.push_back(minChar);
        }
        return ans;
    }
};
