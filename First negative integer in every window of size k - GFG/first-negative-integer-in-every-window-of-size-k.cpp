//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    vector<long long> res;
    queue<long long> q;
    for(int i = 0; i < K; ++i)
        q.push(A[i]);
    
    while(q.size() > 0 && q.front() >= 0)
        q.pop();
    if(q.size() > 0)
        res.push_back(q.front());
    else
        res.push_back(0);
    
    for(int i = K; i < N; ++i)
    {
        q.push(A[i]);
        if(q.size() > K)
            q.pop();
        while(q.size() > 0 && q.front() >= 0)
            q.pop();
        if(q.size() > 0)
            res.push_back(q.front());
        else
            res.push_back(0);
    }
    
    return res;
 }