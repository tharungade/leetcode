//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    bool isValid(int i, int n)
    {
        return i >= 0 && i < n;
    }
    int goodStones(int n,vector<int> &arr){
        // Code here
        vector<int> visited(n, 0);
        // -1 --> bad ones, 11 --> goodones
        for(int j = 0; j < n; ++j)
        {
            if(!visited[j])
            {
                int currInd = j;
                unordered_set<int> stor;
                stor.insert(currInd);
                while(isValid(currInd + arr[currInd], n) && (!visited[currInd + arr[currInd]]) && stor.find(currInd + arr[currInd]) == stor.end())
                {
                    stor.insert(currInd + arr[currInd]);
                    currInd = currInd + arr[currInd];
                }
                if(!isValid(currInd + arr[currInd], n))
                {
                    for(auto & i : stor)
                        visited[i] = 1;
                }
                else
                if(visited[currInd + arr[currInd]])
                {
                    for(auto & i : stor)
                        visited[i] = visited[currInd + arr[currInd]];
                }
                else
                {
                    for(auto & i : stor)
                        visited[i] = -1;
                }
            }
        }
        
        int count = 0;
        for(auto & i : visited)
        {
            if(i == 1)
                count++;
            // cout << i << " ";
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
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends