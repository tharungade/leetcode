//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        // code here
        int val = 2, maxPrime = 1;
        if(N%val == 0)
        {
            maxPrime = val;
            while(N%val == 0)
            {
                N /= val;
            }   
        }
        
        val = 3;
        while(val * val <= N)
        {
            if(N%val == 0)
            {
               maxPrime = val;
               while(N%val == 0)
               {
                 N /= val;
               } 
            }
            val += 2;
        }   
        if(N > 1)
        {
            maxPrime = N;
        }
        
        return maxPrime;
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
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends