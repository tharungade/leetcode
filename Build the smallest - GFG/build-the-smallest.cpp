//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
    string res = "";
    stack<char> stk;
    
    for(auto & i : num)
    {
        while(stk.size() > 0 && stk.top() > i && k > 0)
        {
            stk.pop();
            k--;
        }
        stk.push(i);
    }
    
    while(k--)
    {
        stk.pop();
    }
    
    while(stk.size() > 0)
    {
        res = stk.top() + res;
        stk.pop();
    }
    
    reverse(res.begin(), res.end());
    while(res[res.size()-1] == '0')
        res.pop_back();
    reverse(res.begin(), res.end());
    
    if(res == "")
        res = "0";
        
    return res;
}