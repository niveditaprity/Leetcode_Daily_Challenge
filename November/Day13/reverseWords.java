class Solution {
    public String reverseWords(String s) {
       String ans="";
       int i = 0;
       while(i<s.length()){
           if(s.charAt(i) == ' ') i++;
           else{
               String temp="";
             while(i<s.length() && s.charAt(i) !=' '){
                temp +=s.charAt(i);
                i++;
             }
             if(ans.length() == 0) ans = temp;
             else ans = temp + " " + ans;
           }
       }
       return ans;
  }
}