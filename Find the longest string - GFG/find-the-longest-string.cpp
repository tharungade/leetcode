//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        sort(words.begin(), words.end());
        unordered_set<string> st;
        string ans = "NaN";
        for(auto & i : words)
        {
            if(ans == "NaN" && i.size() == 1)
                ans = i;
            
            
            if(i.size() == 1){
                if(ans.size() == 1 && i < ans)
                    ans = i;
                st.insert(i);
            }
            else
            if(st.find(i.substr(0,i.size()-1)) != st.end())
            {
                if(i.size() > ans.size())
                    ans = i;
                else
                if(i.size() == ans.size() && i < ans)
                    ans = i;
                
                st.insert(i);
            }
        }
        
        if(ans == "NaN")
            ans = "";
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends