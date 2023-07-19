//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int helper(int low, int high, string&A, vector<vector<int>> &dp)
    {
        if(low == high)
        {
            return 1;
        }
        if(low > high)
        {
            return 0;
        }
        
        if(dp[low][high] != -1)
        {
            return dp[low][high];
        }
        
        if(A[low] == A[high])
        {
            return dp[low][high] = 2 + helper(low + 1, high - 1, A, dp);
        }
        
        int incrementLowCase = helper(low + 1, high, A, dp);
        int decrementHighCase = helper(low, high - 1 , A, dp);
        
        return dp[low][high] = max(incrementLowCase, decrementHighCase);
    }
    int longestPalinSubseq(string& A) {
        //code here
        int n = A.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return helper(0, n-1, A, dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends