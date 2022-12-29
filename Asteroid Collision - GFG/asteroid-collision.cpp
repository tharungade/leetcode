//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        stack<int> stk;
        
        for(int i = 0; i < N; ++i)
        {
            if(stk.empty() || asteroids[i] > 0)
                stk.push(asteroids[i]);
            else
            {
                int flag = 1;
                while(stk.size() > 0 && stk.top() > 0 && stk.top() <= abs(asteroids[i])){
                    if(stk.top() == abs(asteroids[i]))
                        flag = 0;
                    stk.pop();
                    if(flag == 0)
                        break;
                }
                    
                if(flag == 1 && (stk.empty() || stk.top() < 0))
                    stk.push(asteroids[i]);
            }
        }
        vector<int> res;
        while(stk.size() > 0)
        {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends