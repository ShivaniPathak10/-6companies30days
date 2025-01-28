class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) 
    {
        vector<long> dp(n+1, 0);
        int ans = 0, mod = 1e9 + 7;
        dp[1] = 1;

        for(int i=1; i<=n; i++)
        {
            if(dp[i] > 0)
            {
                int curr = i+delay;
                while(curr < i+forget and curr <= n) 
                    dp[curr++] = (dp[curr] + dp[i])%mod;
            }
        }
        
        for(int i=n; i>n-forget; i--) ans = (ans + dp[i])%mod;
        return ans;
    }
};