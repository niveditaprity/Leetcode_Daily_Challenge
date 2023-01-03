class Solution {
    public int minDeletionSize(String[] strs) {

        int count =0;

        for(int col=0;col<strs[0].length();col++){

            for(int row = 0;row<strs.length-1;row++){
                
                int ch1 = strs[row].charAt(col);
                int ch2 = strs[row+1].charAt(col);

                if(ch1>ch2){
                    count++;
                    break;
                }
            }
        }

        return count;
        
    }
}