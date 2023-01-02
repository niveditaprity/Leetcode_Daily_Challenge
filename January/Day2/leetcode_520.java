
class Solution {
    private boolean allCapital(String word){
        for(int i=0;i<word.length();i++){
            int ch = word.charAt(i);

            if(!(ch>='A' && ch<='Z')){
                return false;
            }
        }
        return true;
    }
    private boolean allSmall(String word){
        for(int i=0;i<word.length();i++){
            int ch = word.charAt(i);

            if(!(ch>='a' && ch<='z')){
                return false;
            }
        }

        return true;
    }    

    private boolean onlyFirstCapital(String word){
        int i=0;
        char ch = word.charAt(i);
        if(!(ch>='A' && ch<='Z')){
            return false;
        }

        return allSmall(word.substring(i+1));
    }  
      
    public boolean detectCapitalUse(String word) {
         return allSmall(word) || onlyFirstCapital(word) || allCapital(word);
    }
}