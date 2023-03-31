//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        bool parity(int n)
        {
            return (n&1);
        }
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            priority_queue<int> pq;
            vector<int> res;
            for(int i = 0; i < a.size(); ++i)
            {
                if(pq.empty() || parity(a[i]) == parity(pq.top()))
                {
                    pq.push(a[i]);
                }
                else
                {
                    while(pq.size() > 0)
                    {
                        res.push_back(pq.top());
                        pq.pop();
                    }
                     pq.push(a[i]);
                }
            }
            while(pq.size() > 0)
            {
                res.push_back(pq.top());
                pq.pop();
            }
            return res;
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
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends