//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{  
    int mod = (int)1e9 + 7;
public:
    int countPaths(int N){
        // code here 
        long long  numberOfNodes = 1, numberOfZeros = 1;
        while(N--)
        {
            numberOfZeros = ((numberOfNodes - numberOfZeros)%mod + mod)%mod;
            numberOfNodes = (numberOfNodes * 3) % mod;
        }
        
        return numberOfZeros;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends