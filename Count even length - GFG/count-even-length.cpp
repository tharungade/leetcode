//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod = (int)1e9 + 7;
	public:
	void gcdExtended(int a, int b, int &x, int &y)
    {
        if (a == 0)
        {
            x = 0;
            y = 1;
            return ;
        }
     
        int x1, y1; 
        gcdExtended(b%a, a, x1, y1);
     
        x = y1 - (b/a) * x1;
        y = x1;
    }
    
	int compute_value(int n)
	{
	    // Code here
	    int res = 1;
	    long long numerator = 1, denominator = 1, curr;
	    for(int i = 1; i <= n; ++i)
	    {
	        numerator = (numerator*(n-i+1))%mod;
	        denominator = (denominator*i)%mod;
	        int x, y;
	        gcdExtended(denominator, mod, x, y);
	        curr = (numerator*x)%mod;
	        res = (res + (curr*curr)%mod)%mod;
	    }
	    
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends