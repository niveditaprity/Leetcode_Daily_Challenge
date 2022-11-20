class Solution {
public String reverseWords(String s) {
        String [] arr= s.split(" ");
    String ans="";
        for(String p:arr){
            if(!(p.equals("") ||p.contains(" "))){
                ans=p+" "+ans;
            }
        }
    return ans.trim();
    }
}
