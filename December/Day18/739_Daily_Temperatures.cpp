class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
     vector<int>ans(n);
     stack<int>st;
     for(int i = 0;i<n;i++)
     {
         while(st.size()>0 && temperatures[st.top()] < temperatures[i])
         {
             ans[st.top()]=i-st.top();
             st.pop();
         }
         st.push(i);
     } 
     return ans;  
    }
};
