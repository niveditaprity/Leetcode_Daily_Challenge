class Solution {
    public boolean detectCapitalUse(String word) {
        boolean isAllCapital=true;
        if(word.charAt(0)>='A'&& word.charAt(0)<='Z'){
            if(word.length()>=2 && word.charAt(1)>='A' && word.charAt(1)<='Z'){
                isAllCapital=true;
            }
            else
                isAllCapital=false;
        }
        else
            isAllCapital=false;
        for(int i=1;i<word.length();i++){
            if(isAllCapital==true && word.charAt(i)>='a' && word.charAt(i)<='z')
            return false;
            if(isAllCapital==false && word.charAt(i)>='A' && word.charAt(i)<='Z')
                return false;

        }
        return true;
    }
}
