class Solution {
    public String removeDuplicates(String s) {
        StringBuilder str_b = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (str_b.length() > 0 && str_b.charAt(str_b.length() - 1) == c) {
                str_b.deleteCharAt(str_b.length() - 1);
            } else {
                str_b.append(c);
            }
        }
        return str_b.toString();
    }
}