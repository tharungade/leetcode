//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        // code here
        int l , r;
        int mini = 0, counter = 0, maxi = 0, miniInd = 0;
        
        for(int i = 0; i < n;++i)
        {
            if(str[i] == '0')
                counter++;
            else
                counter--;
            if(counter < mini)
            {
                mini = counter;
                miniInd = i + 1;
            }
            if( counter - mini > maxi)
            {
                maxi = counter - mini;
                l = miniInd + 1;
                r = i+1;
            }
        }
        vector<int> res;
        if(maxi == 0)
            res.push_back(-1);
        else{
            res.push_back(l);
            res.push_back(r);
        }
         
         return res;   
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends