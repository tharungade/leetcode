//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> stk;
        for(int i = 0; i < n;++i)
            stk.push(i);
        int one, another, mayBeCelebrity;
        while(true)
        {
            int one = stk.top();
            stk.pop();
            if(stk.empty())
            {
                mayBeCelebrity = one;
                break;
            }
            another = stk.top();
            stk.pop();
            if(M[one][another])
                stk.push(another);
            else
                stk.push(one);
        }
        
        for(int i = 0; i < n; ++i)
            if(i != mayBeCelebrity && (M[mayBeCelebrity][i] == 1 || M[i][mayBeCelebrity] == 0))
                return -1;
        
        return mayBeCelebrity;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends