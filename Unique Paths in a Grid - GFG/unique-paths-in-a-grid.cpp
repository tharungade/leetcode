//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int mod = (int)1e9 + 7;
  public:
    bool isValid(int i, int j, vector<vector<int>> &grid)
    {
        return i < grid.size() && j < grid[0].size() && grid[i][j] == 1;
    }
    int helper(int i, int j, vector<vector<int>> &grid, vector<vector<long long>> &dp)
    {
        if(i == grid.size()-1 && j == grid[0].size()-1)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
            
        return dp[i][j] = ((long long)((isValid(i+1, j, grid))?(helper(i+1,j, grid, dp)):0) + 
              ((isValid(i, j+1, grid))?(helper(i,j+1, grid, dp)):0))%mod;
    }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        if(grid[0][0] == 0)
            return 0;
        vector<vector<long long>> dp(n, vector<long long> (m, -1));
        return helper(0, 0, grid, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends