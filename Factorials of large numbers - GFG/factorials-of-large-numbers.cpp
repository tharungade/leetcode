//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int> res;
        res.push_back(1);
        
        for(int i = 2; i <= N; ++i)
        {
            int siz = res.size(), carry = 0, num;
            for(int j = 0; j < siz; ++j)
            {
                num = (res[j]*i + carry);
                res[j] = num%10;
                carry = num/10;
            }
            while(carry)
            {
                res.push_back(carry%10);
                carry /= 10;
            }
        }
        
        reverse(res.begin(), res.end());
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
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends