class Solution {
public:
    int MOD = 1000000007;
    int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
     vector<int>left(n);
     vector<int>right(n);
     stack<pair<int,int>>st;
        
     for(int i=0;i<n;i++)
     {
         int count = 1 , curr = arr[i];
         while(st.size()>0 && st.top().first>curr)
         {
             count+=st.top().second;
             st.pop();
         }
         st.push({curr,count});
         left[i]=count;
     }
        
     stack<pair<int,int>>s;   
    for(int i=n-1;i>=0;i--)
     {
         
         int count = 1 , curr = arr[i];
         while(s.size()>0 && s.top().first>=curr)
         {
             count+=s.top().second;
             s.pop();
         }
         s.push({curr,count});
         right[i]=count;
         
     }
    //reverse(right.begin(),right.end());
    long long  sum =0;
    for(int i=0;i<n;i++)
    {
    long leftRight = (left[i] * right[i]) % 1000000007;
    int temp = (arr[i] * leftRight) % 1000000007;
    sum = (sum + temp) % 1000000007;
    }
      
    return sum;    
        
    }
};
