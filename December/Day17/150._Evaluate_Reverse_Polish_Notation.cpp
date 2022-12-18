class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
     for(auto x : tokens)
     {
         if(x!="+" && x!="-" && x!="*" && x!="/")
         {
             st.push(stoi(x));
         }
         else
         {
             long long a = st.top();
             st.pop();
             long long b = st.top();
             st.pop();
             if(x=="+")
             {
                 st.push(a+b);
             }
             else if(x=="-")
             {
                 st.push(b-a);
             }
             else if(x=="*")
             {
                 st.push(a*b);
             }
             else
             {
                 st.push(b/a);
             }
         }
     } 
     return st.top(); 
    }
};
