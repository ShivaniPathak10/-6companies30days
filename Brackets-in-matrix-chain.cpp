class Solution {
  public:
    string matrixChainOrder(vector<int> &arr) {
        // code here
        int n= arr.size();
        vector<vector<int>> dp(n, vector<int>(n,0) );
        vector<vector<int>> s (n, vector<int>(n,0) );
        for(int len=2;len<n;len++)
        {
            for(int i=1;i<n-len+1;i++)
            {
                int j=i+len-1;
                dp[i][j]=INT_MAX;
                for(int k=i;k<j;k++)
                {
                    int cost =dp[i][k] +dp[k+1][j]+ arr[i-1]*arr[k]*arr[j];
                    if(cost< dp[i][j])
                    {
                        dp[i][j]=cost;
                        s[i][j]=k;
                    }
                }
            }
        }
    
    
    function<string(int, int)> fn= [&](int i, int j)
    {
        if(i==j) return string(1, 'A'+i-1);
        return "("+ fn(i, s[i][j])+ fn(s[i][j]+1,j)+")";
    };
    
    return fn(1, n-1);
    }
};