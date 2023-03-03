//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long gcd(long long a, long long b)
    {
        if(a == 0)
            return b;
        
        return gcd(b%a, a);
    }
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        // code here
        long long maxi = max(L, B);
        long long g = gcd(L, B);
        vector<long long> res(2);
        
        res[0] = (L*B)/(g*g);
        res[1] = g;
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int L, B;
        cin>>L>>B;
        
        Solution ob;
        vector<long long int> ans = ob.minimumSquares(L, B);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends