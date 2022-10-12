//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        vector<int> res;
        vector<bool> arr(N+1, true);
        
        for(int i = 2; i <= N; i++)
        {
            if(arr[i])
            {
                for(int j = 2; j*i <= N; j++)
                    arr[j*i] = false;
            }
        }
        
        for(int i = 2; i <= N; i++)
            if(arr[i]) res.push_back(i);
            
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends