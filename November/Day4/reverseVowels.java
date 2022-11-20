class Solution {

    public String reverseVowels(String s) {

        char[] chars = s.toCharArray();

        int start = 0;
        int end  = s.length() - 1;

        while (start < end) {
            while (start < end && !isVowel(chars[start])) {
                start++;
            }

            while (start < end && !isVowel(chars[end])) {
                end--;
            }

            if (start < end) {
                char temp = chars[start];
                chars[start++] = chars[end];
                chars[end--] = temp;
            }
        }
        return new String(chars);
    }

    private boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
                || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
}