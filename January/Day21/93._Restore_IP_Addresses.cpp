class Solution {
public:
    bool isvalid(string s)
    {
        int n=s.size();
        if(n==1){
            return true;
        }
        if(n>3||s[0]=='0'){
            return false;
        }
        int num =stoi(s);
        if(num>255){
            return false;
        }
        return true;
    }
    void solve(vector<string>&ans,string temp, int i,int part, string s)
    {
      if(s.size() == i && part == 4)
      {
          ans.push_back(temp.substr(0,temp.size()-1));
          return;
      }
      else if(s.size()== i || part == 4)
      {
          return;
      }
      solve(ans,temp+s[i]+"." ,i+1,part+1,s);
      if(s.size()>i+1 && isvalid(s.substr(i,2)))
      {
       solve(ans,temp+s.substr(i,2)+".",i+2,part+1,s);   
      }
      if(s.size()>i+2 && isvalid(s.substr(i,3)))
      {
       solve(ans,temp+s.substr(i,3)+".",i+3,part+1,s);   
      }

    }
    vector<string> restoreIpAddresses(string s) {
      vector<string>ans;
      if(s.size()>12 || s.size()<4)
      {
          return ans;
      }
      string temp;
      solve(ans,temp,0,0,s); 
      return ans;
    }
};
