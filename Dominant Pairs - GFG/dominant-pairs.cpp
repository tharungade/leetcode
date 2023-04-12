//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int binarySearch(int i, int n,vector<int> &arr)
    {
        int low = 0, high = n/2 - 1, ans = n/2, mid;
        
        while(low <= high)
        {
            mid = low + (high - low)/2;
            if(arr[mid] >= 5*arr[i])
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return n/2 - ans;
    }
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        sort(arr.begin(), arr.begin() + n/2);
        sort(arr.begin() + n/2, arr.end());
        
        int count = 0;
        for(int i = n/2; i < n; ++i)
        {
            count += (binarySearch(i, n, arr));
        }
        
        return count;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends