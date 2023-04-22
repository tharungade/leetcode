//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<long long> res(n, 0);
        vector<pair<long long, int>> tempArr(n);
        for(int i = 0; i < n; ++i)
        {
            tempArr[i].first = arr[i];
            tempArr[i].second = i;
        }
        sort(tempArr.begin(), tempArr.end());
        
        long long sum = tempArr[0].first;
        for(int i = 1; i < n; ++i)
        {
            if(tempArr[i-1].first < tempArr[i].first)
            {
                res[tempArr[i].second] = sum;
            }
            else
            {
                res[tempArr[i].second] = res[tempArr[i-1].second];
            }
            sum += tempArr[i].first;
        }
        
        return res;
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends