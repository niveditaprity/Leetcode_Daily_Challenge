class Solution {
public:
    int find(string&text1, int n1, string&text2, int n2,vector<vector<int>>&dp)
    {
        if(n1<0 || n2<0)
        {
            return 0;
        }
        if(dp[n1][n2]!=-1)
        {
            return dp[n1][n2];
        }
        if(text1[n1] == text2[n2])
        {
            return dp[n1][n2] =  1 + find(text1,n1-1,text2,n2-1,dp);
        }
        return dp[n1][n2] = max(find(text1,n1-1,text2,n2,dp),find(text1,n1,text2,n2-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.size();
    int n2 = text2.size();
    vector<vector<int>> dp( n1 , vector<int> (n2, -1)); 
    return find(text1,n1-1,text2,n2-1,dp);    
    }
};
