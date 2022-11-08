class Solution {
    public String makeGood(String s) {
        Stack<Character> st=new Stack<>();
        for(char c:s.toCharArray()){
            if(!st.isEmpty() && Math.abs(st.peek()-c)==32 ){
                st.pop();
            }
            else
                st.push(c);
            
        }
        String p="";
        while(!st.isEmpty()){
            p=st.pop().toString()+p;
        }
        return p;
    }
}
