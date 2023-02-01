class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
      int n1 = str1.size();
      int n2 = str2.size();
      if(str1 + str2 != str2 + str1) 
      {
          return "";
      }
      return str1.substr(0,gcd(n1,n2));
    }
};
