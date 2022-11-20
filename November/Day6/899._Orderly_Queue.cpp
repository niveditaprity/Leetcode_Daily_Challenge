class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        if (k==1)
        {
            int n=s.size();
            string doublestring=s+s;
            string ans=s;
            for (int i=1;i<n;i++) 
            {
                string str=doublestring.substr(i,n);
                if (str<ans) 
                {
                    ans = str;
                }
            }
            return ans;
            
        }
        sort(s.begin(),s.end());
        return s;
        
    }
};