//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    int findMinIndex(vector<long long> &arr)
    {
        int minInd = 0, arrLength = arr.size();
        for(int i = 1; i < arrLength; ++i)
        {
            if(arr[i] < arr[minInd])
            {
                minInd = i;
            }
        }
        
        return minInd;
    }
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        vector<long long> columnSum(n), rowSum(n);
        long long maxSum = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                rowSum[i] += matrix[i][j];
                columnSum[j] += matrix[i][j];
                maxSum = max(maxSum, rowSum[i]);
                maxSum = max(maxSum, columnSum[j]);
            }
        }
        // cout << maxSum << endl;
        // for(auto & i : rowSum)
        // cout << i << " ";
        // cout << endl;
        // for(auto & i : columnSum)
        // cout  << i << " ";
        
        // cout << endl;
        int result = 0;
        for(int i = 1; i <= 2*n; ++i)
        {
            int rowMinInd = findMinIndex(rowSum);
            int columnMinInd = findMinIndex(columnSum);
            int minimumAdd = maxSum - max(rowSum[rowMinInd], columnSum[columnMinInd]);
            result += minimumAdd;
            rowSum[rowMinInd] += minimumAdd;
            columnSum[columnMinInd] += minimumAdd;
        }
        
        return result;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends