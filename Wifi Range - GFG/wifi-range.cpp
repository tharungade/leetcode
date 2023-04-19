//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        // code here
        int curRangeRight = 0, curRangeLeft = 0;
        for(int i = 0; i < N; ++i)
        {
            if(S[i] == '1')
            {
                curRangeRight = X;
            }
            else
            if(curRangeRight > 0)
            {
                S[i] = '-';
                curRangeRight--; 
            }
            
            if(S[N-i-1] == '1')
            {
                curRangeLeft = X;
            }
            else
            if(curRangeLeft > 0)
            {
                S[N-i-1] = '-';
                curRangeLeft--; 
            }
        }
        
        for(int i = 0; i < N; ++i)
        {
            if(S[i] == '0')
            {
                return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends