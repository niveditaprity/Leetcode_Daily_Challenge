class Solution {

    private int countVowels(String s){
        int count =0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='a' || s.charAt(i)=='e' || s.charAt(i)=='i' || s.charAt(i)=='o' || s.charAt(i)=='u' || s.charAt(i)=='A' || s.charAt(i)=='E' || s.charAt(i)=='I' || s.charAt(i)=='O' || s.charAt(i)=='U')
                count++;
        }
        return count;
    }
    public boolean halvesAreAlike(String s) {
        int n =s.length();
        String s1 = s.substring(0,n/2);
        String s2 = s.substring(n/2);

        return countVowels(s1)==countVowels(s2);
    }
}