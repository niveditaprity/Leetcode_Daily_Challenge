class Solution {
    public int longestPalindrome(String[] words) {
        Map<String, Integer> map = new HashMap<>();
        
        for(String s: words) {
            map.put(s, map.getOrDefault(s, 0) + 1);
        }
        
        int ans = 0;
        int len = 0;
        boolean flag = false;
        
        for(Map.Entry<String, Integer> entry: map.entrySet()) {
            String w = entry.getKey();
            
            char[] arr = w.toCharArray();
            if(arr[0] == arr[1]) {
                
                int v = map.get(w);
                // ll ll ll
                if(v % 2 == 0) {
                    len += v;
                } else {
                    flag = true;
                    len += v - 1;
                }
                // map.remove(w);
                
                
                
            } else {
                
                String rev = "" + arr[1] + arr[0];
                System.out.println(rev);
                if(map.containsKey(rev)) {
                    ans += Math.min(map.get(w), map.get(rev)) * 2;
                }
          
                // map.remove(w);
                // map.remove(rev);
            }
        } 
        
        if(flag) {
            ans += (len *2) + 2;
        } else {
            ans +=  (len* 2);
        }
        
        return ans;
    }
}
