class Solution {
public:
    
    bool search(int index, int i, int j ,vector<vector<char>>& board, string word)
    {
      if(index == word.size())
      {
          return true;
      }
      if(i<0 or j<0 or i>=board.size() or j>=board[0].size())
      {
          return false;
      }
      bool ans = false;
     if(word[index] == board[i][j])
     {
         board[i][j] = '*';
         
         ans = search(index+1,i+1,j,board,word) or 
               search(index+1,i,j+1,board,word) or
               search(index+1,i-1,j,board,word) or
               search(index+1,i,j-1,board,word);
         
        board[i][j] = word[index];
     }
        
     return ans;   
    }
    
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
      int m = board[0].size();
      int n = board.size();
      int index = 0; 
      bool ans = false;
     
      for(int i=0; i<n ;i++)
      {
          for(int j = 0; j<m; j++)
          {
              if(word[index] == board[i][j])
              {
                if(search(index,i,j,board,word))  
                {
                    return true;
                }
              }
          }
      }
        return ans;
    }
};