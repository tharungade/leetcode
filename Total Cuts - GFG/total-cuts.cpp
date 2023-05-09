//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        // Code here
        int count = 0, largeLeft = A[0], smallestRight = A[N-1];
        vector<int> largestInLeft(N), smallestInRight(N);
        for(int i = 0; i < N; ++i)
        {
            largeLeft = max(largeLeft, A[i]);
            smallestRight = min(smallestRight, A[N-i-1]);
            largestInLeft[i] = largeLeft;
            smallestInRight[N-i-1] = smallestRight;
        }
        
        for(int i = 0; i  < N-1; ++i)
        {
            if(largestInLeft[i] + smallestInRight[i+1] >= K)
            {
                count++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends