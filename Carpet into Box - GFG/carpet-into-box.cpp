//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int helper(int A, int B, int C, int D)
    {
        int count = 0;
        while(A > C){
            A /= 2;
            count++;
        }
        while(B > D)
        {
            B /= 2;
            count++;
        }
        
        return count;
    }
    int carpetBox(int A, int B, int C, int D){
        //code here
        return min(helper(A,B,C,D),  helper(B,A,C,D));
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends