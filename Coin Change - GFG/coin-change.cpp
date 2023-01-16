//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long helper(int ind, int sum,int N, int coins[], vector<vector<long long>> &dp)
    {
        if(sum == 0)
            return 1;
        if(sum < 0 || ind >= N) 
            return 0;
        
        if(dp[ind][sum] != -1)
            return dp[ind][sum];
       return dp[ind][sum] = helper(ind, sum-coins[ind], N, coins, dp) + helper(ind + 1, sum, N, coins, dp);
    }
    long long int count(int coins[], int N, int sum) {
        // code here.
        vector<vector<long long>> dp(N+1, vector<long long> (sum + 1, -1));
        return helper(0, sum, N, coins, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends