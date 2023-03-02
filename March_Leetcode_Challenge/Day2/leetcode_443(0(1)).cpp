class Solution {
public:
    int compress(vector<char>& chars) {
       int count = 1;
       int j = 0;
       if(chars.size()==1)
       {
           return 1;
       }
       for(int i = 1; i<=chars.size();i++)
       {
           count = 1;
           while(i<chars.size() && chars[i] == chars[i-1])
           {
               count++;
               i++;
           }
           chars[j++] = chars[i-1];
           if(count>1)
           {
                  string c = to_string(count);
                  for(auto ch : c)
                  {
                      chars[j++]= (char)ch;
                  }
              }
       }
          
       return j;
    }
};
