//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        // code here
        if(M != N)
            return 0;
        
        bool flag = true;
        int i = 0, j = 0;
        while(i < M && j < N)
        {
            while(i < M && S[i] == '#')
                i++;
            if(i < M)
                flag = false;
            
            while(j < N && T[j] == '#')
                j++;
                
            if(j < N)
            {
                if(i < M && S[i] == T[j])
                    flag = true;
                else
                {
                    flag = false;
                    break;
                }
            }
            else
                break;
                
            i++;
            j++;
        }
        
        if(flag) return 1;
        
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends