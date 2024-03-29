//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        // code here
        priority_queue<int> pq;
        for(auto & i : arr)
            pq.push(-i);
        
        int res  = 0, val1, val2;
        while(pq.size() > 1)
        {
            val1 = pq.top();
            pq.pop();
            val2 = pq.top();
            pq.pop();
            res -= (val1 + val2);
            pq.push(val1+val2);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends