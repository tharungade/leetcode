//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        int maxi = 0, n = s.size();
        bool flag;
        for(int i = 0; i < n; ++i)
        {
            flag = true;
            for(int j = 0; j <= i; ++j)
            {
                if(i+j+1 >= n || s[j] !=  s[i+j+1])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                maxi = i + 1;
        }
        int res = n;
        if(maxi)
            res = maxi + 1 + (n- 2*maxi);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends