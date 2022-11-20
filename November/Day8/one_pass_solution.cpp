class Solution {
public:
    string makeGood(string s) {
     string ans;
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            ans.push_back(s[i]);
            while(ans.size() && abs(ans.back()-s[i+1])==32)                            {
                ans.pop_back();
                i++;
              }
        }
        
        return ans;
     }
};