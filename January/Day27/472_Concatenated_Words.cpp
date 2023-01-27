class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
     
        vector<string> res;
        int size=words.size();
        unordered_map<string, int> mp;
        for(auto word : words)
        {
            mp[word]++;
        }
        for(int i=0;i<size;i++){           
            int n=words[i].size();
            if(solve(words[i], 0,0, n,mp)>=2)
            {
                res.push_back(words[i]);
            }
        }
        
        return res;
    }
    
    
    int  solve(string&s, int index, int part, int n,unordered_map<string, int>&mp){
        
        if(index>=n)         
           return part;
        
        
        string temp="";
        for(int i=index;i<n;i++){
            temp+=s[i];
            
            if(mp.find(temp)!=mp.end()){
                int ans=solve(s, i+1, part+1, n,mp);
             
                if(ans>=2)
                    return ans;
            }
        }
        
    return -1;
        
    }  
};
