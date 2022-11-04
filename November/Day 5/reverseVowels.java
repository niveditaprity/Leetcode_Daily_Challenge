class Solution {
    public String reverseVowels(String s) {
        Set<Character> vow = Stream.of('a','e','i','o','u','A','E','I','O','U').collect(Collectors.toSet());
        
        char[] arr = s.toCharArray();
        
        int l = 0;
        int r = s.length()-1;
        
        while(l < r && l < s.length() && r > 0) {
            boolean lVow = false;
            while(!lVow && l < r){
                if(vow.contains(arr[l])) {
                    lVow = true;
                } else {
                    l++;
                }
            }
            
            boolean rVow = false;
            while(!rVow && l < r){
                if(vow.contains(arr[r])){
                    rVow = true;
                } else {
                    r--;
                }
            }
            
            char swap = arr[l];
            arr[l] =  arr[r];
            arr[r] = swap;
            l++;
            r--;

            
        }
        
        return String.valueOf(arr);
    }
}
