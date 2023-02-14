class Solution {
public:
    string addBinary(string a, string b) {

       int i = a.size()-1,j = b.size()-1,carry = 0,sum = 0;
       string ans;
       while(i>= 0 || j>=0)
       {
           sum = carry;
           if(i >= 0)
           {
               sum += (a[i]-'0');
               i--;
           }
           if(j >= 0)
           {
               sum += (b[j]-'0');
               j--;
           }
           if(sum>1)
           {
               ans += to_string(sum%2);
               carry = 1;
           }
           else
           {
               carry = 0;
               ans += to_string(sum);
           }
       }
       if(carry == 1)
       {
          ans += ("1");
       }
       reverse(ans.begin(),ans.end());
       return ans;

    }
};
