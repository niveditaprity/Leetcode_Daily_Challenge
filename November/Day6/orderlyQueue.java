class Solution {
    public String orderlyQueue(String s, int k) {
        if (k > 1) {
            char arr[] = s.toCharArray();
            Arrays.sort(arr);
            return new String(arr);
        }
        String ans = s;
        for (int i = 1; i < s.length(); i++) {
            String tmp = s.substring(i) + s.substring(0, i);
            if (tmp.compareTo(ans) < 0) ans = tmp;
        }
        return ans;
    }
}