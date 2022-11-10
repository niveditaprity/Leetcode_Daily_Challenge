class Solution {
public:
    string removeDuplicates(string s) {
      string ans;
      for(int i=0;i<s.size();i++)
      {
         if(ans.back() == s[i])
         {
             ans.pop_back();
          }
          else
          {
              ans+=s[i];
          }
      }
        return ans;
    }
};