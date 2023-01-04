//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
bool comp(const vector<int> &first, const vector<int> &second)
    {
        if(first[0] == second[0])
        {
            if(first[1] == second[1])
                return first[2] > second[2];
            
            return first[1] < second[1];
        }
        
        return first[0] < second[0];
    }
class Solution {
  public:
    
    int helper(int ind, vector<vector<int>> &intervals, vector<int> &dp)
    {
        if(ind >= intervals.size())
            return 0;
            
        if(dp[ind] != -1)
            return dp[ind];
            
        int tempInd = ind + 1;
        while(tempInd < intervals.size() && intervals[tempInd][0] < intervals[ind][1])
            tempInd++;
        int pick = intervals[ind][2] + helper(tempInd, intervals, dp);
    
        int nonPick = helper(ind + 1, intervals, dp);
        
        return dp[ind] = max(pick , nonPick);
    }
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // Write your code here.
        sort(intervals.begin(), intervals.end(), comp);
        vector<int> dp(n, -1);
        
        return helper(0, intervals, dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends