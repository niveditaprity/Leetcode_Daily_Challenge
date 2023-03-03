class Solution {
public:
    int strStr(string haystack, string needle) {
      int n1 = haystack.size();
      int n2 = needle.size();
      if(n2>n1)
      {
          return -1;
      }
    int j = 0;
    int i = 0;
    int start = 0;
    while(i < n1 && j < n2)
    {
        if(haystack[i] == needle[j])
        {
          if(i-start+1 == n2) 
          {
              return start;
          } 
          j++;
          i++;
        }
        else
        {
          j=0;
          start++;
          i = start;
        }
    }
    return -1;
}
};
