//Recursive solution

class Solution {
public:
    int findlongestPalindromeSubseq(string s, int start, int end) {
        if (start > end) {
            return 0;
        }
        if (start == end) {
            return 1;
        }
        if (s[start] == s[end]) {
            return 2 + findlongestPalindromeSubseq(s, start+1, end-1);
        }
        else {
            return max(findlongestPalindromeSubseq(s, start+1, end), findlongestPalindromeSubseq(s, start, end-1));
        }
    }
    
    int longestPalindromeSubseq(string s) {
        return findlongestPalindromeSubseq(s, 0, s.size()-1);
    }
};

// Memoization

class Solution {
public:
    int findlongestPalindromeSubseq(string&s, vector<vector<int>>& dp, int start, int end) {

        if (start > end) {
            return 0;
        }
        else if (start == end) {
            return 1;
        }
         if (dp[start][end] != -1) {
            return dp[start][end];
        }
        else if (s[start] == s[end]) {
            return dp[start][end] = 2 + findlongestPalindromeSubseq(s, dp, start+1, end-1);
        }
        else {
           return  dp[start][end] = max(findlongestPalindromeSubseq(s, dp, start+1, end), findlongestPalindromeSubseq(s, dp, start, end-1));
        }
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return findlongestPalindromeSubseq(s, dp, 0, n-1);
    }
};
