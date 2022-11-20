class Solution {
public:
    struct TrieNode{
        TrieNode*child[26];
        bool flag=false;
        string str;
        bool containChar(char ch)
        {
         return child[ch-'a']!=NULL;
        }
        void putNode(char ch,TrieNode*node)
        {
            child[ch-'a'] = node;
        }
        TrieNode*getNode(char ch)
        {
           return child[ch-'a']; 
        }
        void setEnd()
        {
            flag = true;
        }
       bool isEnd()
        {
            return flag;
        }
    };
    TrieNode*root = new TrieNode(); 
    void insert(string word) {
      TrieNode *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containChar(word[i])) {
				node->putNode(word[i], new TrieNode());
			}
			//moves to reference trie
			node = node->getNode(word[i]);
		}
		node->setEnd();
        node->str = word; 
    }
    void dfs(vector<vector<char>>& board,int i,int j,TrieNode*node,set<string>& res,vector<vector<bool>>& visit){ 
    if(i<0 || j<0 || i>=board.size() || j>= board[0].size())
    {
        return;
    }
        
    node = node->getNode(board[i][j]);
    if(visit[i][j] || !node)return ;
   
    if(node->isEnd()) res.insert((node->str));
    visit[i][j] = true;
    dfs(board,i+1,j,node,res,visit);
    dfs(board,i-1,j,node,res,visit);
    dfs(board,i,j+1,node,res,visit);
    dfs(board,i,j-1,node,res,visit);
    visit[i][j]= false;
}
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> res;
        for(string &s:words){
            insert(s);
        }
       vector<vector<bool>> visit(board.size(),vector<bool>(board[0].size(),false));
        for(int i = 0 ;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
               dfs(board,i,j,root,res,visit);
            }
        }
        vector<string> ans(res.begin(),res.end());
       return ans;  
    }
};
