class Solution {
public:
    int MOD = 1e9+7;

    int solve(int n, int zero, int one)
    {
        if(n == 0)
        {
            return 1;
        }
        if(n<0)
        {
            return 0;
        }
        int total = 0;
        if(n >= zero)
        {
            total+= solve(n-zero,zero,one);
        }
        if(n >= one)
        {
            total+=solve(n-one,zero,one);
        }
        return total%MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        long long int ans = 0;
        for(int len = low; len<=high; len++)
        {
          ans+=solve(len, zero, one) % MOD;
        }
        return ans%MOD;
    }
};




class Solution {
public:
    int MOD = 1e9+7;

    int solve(int n, int zero, int one, vector<long long int>&dp)
    {
        if(n == 0)
        {
            return 1;
        }
        if(n<0)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int total = 0;
        if(n >= zero)
        {
            total+= solve(n-zero,zero,one,dp);
        }
        if(n >= one)
        {
            total+=solve(n-one,zero,one,dp);
        }
        dp[n] = total%MOD;
        return dp[n];
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        long long int  ans = 0;
        vector<long long int>dp(high+1, -1);
        for(int len = low; len<=high; len++)
        {
          ans+=solve(len, zero, one, dp)% MOD;
        }
        return ans%MOD;
    }
};


class Solution {
public:
    int MOD = 1e9+7;

    int countGoodStrings(int low, int high, int zero, int one) {
        long long int  ans = 0;
        vector<long long int>dp(high+1, 0);
        dp[0] = 1;
        for(int len = 1; len<=high; len++)
        {
            int total = 0;
            if(len>=zero)
            {
                total+=dp[len-zero];
            }
            if(len>=one)
            {
                total+= dp[len-one];
            }

            dp[len] = total%MOD;
        }

        for(int len = low; len<=high; len++)
        {
          ans+= dp[len];
        }
        return ans%MOD;
    }
};
