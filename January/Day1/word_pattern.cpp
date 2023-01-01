//https://leetcode.com/problems/word-pattern/description/

class Solution {
public:
   void split(string &s,vector<string>&ans) 
{
    istringstream ss(s);
 
    string word;
    while (ss >> word)
    {
    ans.push_back(word);
    }
}
    bool wordPattern(string pattern, string s) {
    unordered_map<char,string>mp;
    vector<string>v;
    unordered_set<string>taken;
    split(s, v);
    if(pattern.size()!=v.size())
    {
        return false;
    }
    for(int i=0;i<pattern.size();i++)
    {
      if(mp.find(pattern[i])==mp.end() && taken.find(v[i])== taken.end()) 
      {
      mp[pattern[i]]=v[i];
      taken.insert(v[i]);
      } 
      else
      {
          if(mp[pattern[i]]!=v[i])
          {
              return false;
          }
      }
    }
return true;
    }
};
