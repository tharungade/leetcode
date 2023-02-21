//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int helper(int x1, int y1, int x2, int y2)
    {
        return abs(x1-x2) + abs(y1-y2);
    }
    int minIteration(int N, int M, int x, int y){    
        // code here
        return max({helper(x, y, 1, 1), 
                    helper(x, y, 1, M),
                    helper(x, y, N, 1),
                    helper(x, y, N, M)
        });
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends