//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
        unordered_map<int, int> st;
        for(auto & i : arr)
        {
            st[i]++;
        }
        int count = 0;
        for(auto & i : arr)
        {
            if(st[i] > 1 || (i != 1 && st[1] > 0))
            {
                count++;
                continue;
            }
            
            for(int j = 2; j * j <= i; j++)
            {
                if(i %j == 0)
                {
                    if(st[j] > 0 || st[i/j] > 0)
                    {
                        count++;
                        break;
                    }
                }
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends