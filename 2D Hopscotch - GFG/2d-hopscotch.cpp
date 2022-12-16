//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isValid(int i, int j, int n, int m)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    int giveTop(int i, int j, int n, int m, vector<vector<int>> &mat)
    {
        int res = 0;
        if(isValid(i-1,j,n,m))
            res += mat[i-1][j];
        if(j&1)
        {
            if(isValid(i,j-1,n,m))
                res += mat[i][j-1];
            if(isValid(i,j+1,n,m))
                res += mat[i][j+1];
        }
        else
        {
            if(isValid(i-1,j-1,n,m))
                res += mat[i-1][j-1];
            if(isValid(i-1,j+1,n,m))
                res += mat[i-1][j+1];
        }
        return res;
    }
    int giveBottom(int i, int j, int n, int m, vector<vector<int>> &mat)
    {
        int res = 0;
        if(isValid(i+1,j,n,m))
            res += mat[i+1][j];
        if(j&1)
        {
            if(isValid(i+1,j-1,n,m))
                res += mat[i+1][j-1];
            if(isValid(i+1,j+1,n,m))
                res += mat[i+1][j+1];   
        }
        else
        {
            if(isValid(i,j-1,n,m))
                res += mat[i][j-1];
            if(isValid(i,j+1,n,m))
                res += mat[i][j+1];
        }
        return res;
    }
    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)
    {
        // code here
        int res = 0;
        if(ty == 0)
        {
            res += giveTop(i,j,n,m,mat);
            res += giveBottom(i,j,n,m,mat);
        }
        else
        {
            if(isValid(i-1,j,n,m))
                res += giveTop(i-1,j,n,m,mat);
            if(isValid(i+1,j,n,m))
                res += giveBottom(i+1,j,n,m,mat);
            
            if(isValid(i,j-2,n,m))
                res += mat[i][j-2];
            if(isValid(i-1,j-2,n,m))
                res += mat[i-1][j-2];
            if(isValid(i+1,j-2,n,m))
                res += mat[i+1][j-2];
            
            if(isValid(i,j+2,n,m))
                res += mat[i][j+2];
            if(isValid(i-1,j+2,n,m))
                res += mat[i-1][j+2];
            if(isValid(i+1,j+2,n,m))
                res += mat[i+1][j+2];
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>ty>>i>>j;
        
        Solution ob;
        cout<<ob.hopscotch(n, m, mat, ty, i, j)<<"\n";
    }
    return 0;
}
// } Driver Code Ends