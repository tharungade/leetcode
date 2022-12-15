//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
    string helper(string &s, int n)
    {
        int times = n/26, ind = n%26;
        
        string res = "";
        while(times--)
            res += s;
        res += s.substr(0, ind);
        
        return res;
    }
    int sumOfDigits(int n)
    {
        int res = 0;
        while(n)
        {
            res += n%10;
            n /= 10;
        }
        
        return res;
    }
    string BalancedString(int N) {
        // code here
        string str = "abcdefghijklmnopqrstuvwxyz";
        string rev = str;
        reverse(rev.begin(), rev.end());
        string res = "", temp;
        int n = N;
        while(N > 26)
        {
            res += str;
            N -= 26;
        }
        if(N&1)
        {
            if(sumOfDigits(n)&1)
            {
                res += helper(str, (N-1)/2);
                temp = helper(rev, (N+1)/2);
                reverse(temp.begin(), temp.end());
                res += temp;
            }
            else
            {
                res += helper(str, (N+1)/2);
                temp = helper(rev, (N-1)/2);
                reverse(temp.begin(), temp.end());
                res += temp;
            }
        }
        else
        {
            res += helper(str, N/2);
            temp = helper(rev, N/2);
            reverse(temp.begin(), temp.end());
            res += temp;
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends