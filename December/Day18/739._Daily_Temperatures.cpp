class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n = temp.size();
        vector<int> ans(n);
        
        stack< pair<int,int> > s;
        s.push({-1, -1});
        
        for(int i = n-1; i >= 0; i--)
        {
            while(temp[i] >= s.top().first && s.top().first != -1)
            {
                s.pop();
            }
            if(s.top().second == -1)
                ans[i] = 0;
            else
                ans[i] = s.top().second-i;
            
            s.push({temp[i], i});            
        }
        return ans;
    }
};
