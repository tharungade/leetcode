//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int helper(long long n, vector<int> &primes)
    {
        int low = 0, high = primes.size()-1, ans =-1,  mid;
        long long val;
        while(low <= high)
        {
          mid = low + (high - low)/2;
          val = (long long)primes[mid]*primes[mid];
          
          if(val <= n)
          {
              ans = mid + 1;
              low = mid + 1;
          }
          else
            high = mid - 1;
        }
        
        return ans;
    }
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<int> arr(1000001, 1), primes;
        
        for(int i= 2; i*i <= 1000000; ++i)
        {
            if(arr[i])
            {
                for(int j = 2; j*i <= 1000000; ++j)
                    arr[j*i] = 0;
            }
        }
        
        for(int i = 2; i <= 1000000; ++i)
            if(arr[i])
                primes.push_back(i);
                
        
        vector<int> res;
        
        for(auto & i : query)
        {
            if(i < 4)
                res.push_back(0);
            else
                res.push_back(helper(i, primes));
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends