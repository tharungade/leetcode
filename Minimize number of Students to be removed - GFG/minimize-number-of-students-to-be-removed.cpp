//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int H[], int N) {
        // code here
        vector<int> arr;
        arr.push_back(H[0]);
        
        for(int i = 1 ; i < N; ++i)
        {
            if(H[i] > arr[arr.size()-1])
                arr.push_back(H[i]);
            else
            {
                int low = 0, high = arr.size()-1;
                int ind = arr.size()-1;
                
                while(low <= high)
                {
                    int mid = low + (high -low)/2;
                    if(arr[mid] >= H[i]){
                        ind = mid;
                        high = mid - 1;
                    }
                    else
                        low = mid + 1;
                }
                
                arr[ind] = H[i];
            }
        }
        
        return N-(int)arr.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends