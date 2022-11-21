class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m= maze[0].size(),n = maze.size();
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        q.push({entrance[0],entrance[1]});
        visited[entrance[0]][entrance[1]] = 1;
        int level = 0;
        int dr[4] = {1 , -1 ,  0 , 0};
        int dc[4] = {0 ,  0 , -1 , 1};
        
        while(!q.empty())
        {
            int size = q.size();
            level++;
            for(int i=0;i<size;i++)
            {
                auto x = q.front();
                q.pop();
                int row = x.first;
                int col = x.second;
                for(int j=0;j<4;j++)
                {
                    int new_row = row + dr[j];
                    int new_col = col + dc[j];
                    if(new_row>= 0 && new_col >=0 && new_row<n && new_col<m)
                    {
                    
                    if(maze[new_row][new_col] == '+' or visited[new_row][new_col] == 1)
                    {
                        continue;
                    }
                        
                    if(new_row == 0 or new_col == 0 or new_row == n-1 or new_col == m-1)
                    {
                        return level;
                    }
                    q.push({new_row,new_col});
                    visited[new_row][new_col] = 1; 
                } 
                }
            }
        }
        
        
     return -1;   
    }
};