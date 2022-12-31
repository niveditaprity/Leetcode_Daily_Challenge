class Solution {
    
    int ans;
    int cnt;
    
    void dfs(int i, int j, int tar, vector<vector<int>>& grid, int empty)
    {
        int n = grid.size();
        int m = grid[0].size();
        
         if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == -1)
            return;
        
        if(grid[i][j] == tar && empty == cnt)
        {
            ans++;
            return;
        }
        
        int val = grid[i][j];
        grid[i][j] = -1;
        
        
            dfs(i+1, j, tar, grid, empty+1);

          
            dfs(i-1, j, tar, grid, empty+1);


            dfs(i, j+1, tar, grid, empty+1);

          
            dfs(i, j-1, tar, grid, empty+1);

             
      
        grid[i][j] = val;
        return;
        
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        cnt = 0; //cnt how many 0s or empty
        int start_x = 0;
        int start_y = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0)
                    cnt++;
                
                if(grid[i][j] == 1)
                {
                    start_x = i;
                    start_y = j;
                }
            }
        }
        
        cnt++;
        
        int empty = 0;
        
        dfs(start_x, start_y, 2, grid, empty);
        
        return ans;
    }
};
