class Solution {
public:
    int mod = 1e9 + 7;
    int func(int n, int k, int target, vector<vector<int>> &dp)
    {
        if(n <= 0) return (target == 0);
        
        int res = 0;
        for(int i = 1; i <= k; i++){
            if(target >= i){
             if(dp[n-1][target-i] == -1)
                 dp[n-1][target-i] = func(n-1,k,target-i,dp);
            res = (res + dp[n-1][target-i])%mod;
            }
        }
        
        return res;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        return func(n,k,target,dp);
    }
};