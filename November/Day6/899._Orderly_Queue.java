class Solution {
    public String orderlyQueue(String s, int k) {
        if(k>1){
            char tempArray[] = s.toCharArray();
            Arrays.sort(tempArray);
            return new String(tempArray);
        }
            
        int n=s.length();
        String doublestring=s+s;
        String ans=s;
        for(int i=1;i<n;i++){
            String sub=doublestring.substring(i,n+i);
            if(ans.compareTo(sub)>0)ans=sub;
            
        }
        return ans;
        
    }
}
