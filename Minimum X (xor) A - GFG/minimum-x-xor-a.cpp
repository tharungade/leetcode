//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int count = 0, r = 0;
        while(b){
            count += (b&1);
            b >>= 1;
        }
        vector<int> res;
        while(a)
        {
            res.push_back((a&1));
            a >>= 1;
        }
        int i= res.size()-1;
        for( ; i >= 0 && count > 0; --i)
        {
            if(res[i] == 1){
                count--;
                r += pow(2, i);
            }
        }
        
        if(count != 0)
        {
            int j = 0;
            while(count > 0)
            {
                if(j >= res.size() || res[j] == 0)
                {
                    r += pow(2, j);
                    count--;
                }
                j++;
            }
        }
        
        return r;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends