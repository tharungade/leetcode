//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        unordered_map<int,int> mp;
        int minFreq = INT_MAX;
        for(int i = 0; i < n; ++i)
        {
            mp[arr[i]]++;
        }
        for(int i = 0; i < n; ++i)
        {
            minFreq = min(minFreq, mp[arr[i]]);
        }
        int res = INT_MIN;
        for(int i = 0; i < n;++i)
        {
            if(mp[arr[i]] == minFreq && arr[i] > res)
            {
                res = arr[i];
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends