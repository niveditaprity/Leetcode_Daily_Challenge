class Solution {
public:
    long long solve(vector<vector<int>>& questions, int i, int n)
    {
        if(i>n)
        {
            return 0;
        }
        
        long long solveProblem = questions[i][0] + solve(questions, i+questions[i][1]+1, n);
        long long skipProblem = solve(questions, i+1, n);
        return max(solveProblem, skipProblem);

    }
    long long mostPoints(vector<vector<int>>& questions) {
       int n = questions.size();
       return solve(questions, 0, n-1);
    }
};






class Solution {
public:
    long long solve(vector<vector<int>>& questions, int i, int n,vector<long long>&dp)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        
        long long solveProblem = questions[i][0] + solve(questions, i+questions[i][1]+1, n, dp);
        long long skipProblem = solve(questions, i+1, n, dp);
        dp[i] = max(solveProblem, skipProblem);
        return dp[i];

    }
    long long mostPoints(vector<vector<int>>& questions) {
       int n = questions.size();
       vector<long long>dp(n,-1);
       return solve(questions, 0, n, dp);
    }
};


class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
       int n = questions.size();
        vector<long long> dp(n+1, 0); 
        
        for(int i=n-1; i>=0; i--) { 
            int skip = min(n, i+questions[i][1]+1);
            long long solveProblem = questions[i][0] + dp[skip];
            long long skipProblem = dp[i+1];
            dp[i] = max(solveProblem, skipProblem);
        }
        
        return dp[0];
    }
};
