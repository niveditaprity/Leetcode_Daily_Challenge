class Solution {
    public int minFlipsMonoIncr(String s) {
        int countone=0;
        int flip=0;
        for(char c:s.toCharArray()){
            if(c=='1')countone++;
            if(c=='0' && countone>0)flip++;
           flip= Math.min(countone,flip);
        }
        return flip;
    }
}
