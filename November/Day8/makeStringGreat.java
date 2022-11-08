class Solution {
   public String makeGood(String s) {
       int end = 0;
       char arr[] = s.toCharArray();
        for (int curr = 0; curr < s.length(); curr++) {
            if (end > 0 && Math.abs(arr[curr] - arr[end-1]) == 32)
                end--;
            else {
                arr[end] = arr[curr];
                end++;
            }
        }

        return  new String(arr).substring(0, end); 
    }
}