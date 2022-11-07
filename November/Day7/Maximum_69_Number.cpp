class Solution {
public:
    int maximum69Number (int num) {
       string str = to_string(num);
       for(auto &ch :str)
       {
           if(ch=='6')
           {
               ch='9';
               break;
           }
       }
        return stoi(str);
    }
};