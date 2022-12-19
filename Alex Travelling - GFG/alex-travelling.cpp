//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int curr, vector<vector<pair<int,int>>> &arr, vector<int> &visited)
    {
        visited[curr] = 1;
        for(auto & i : arr[curr])
        {
            if(!visited[i.first])
                dfs(i.first, arr, visited);
        }
    }
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<vector<pair<int,int>>> arr(n+1);
        vector<int> visited(n+1, 0);
        for(auto & i : flights)
            arr[i[0]].push_back({i[1], i[2]});
        
        dfs(k,arr,visited);
        for(int i = 1; i <= n; ++i)
            if(!visited[i])
                return -1;
        
        visited = vector<int> (n+1, INT_MAX);
        visited[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});
        
        while(pq.size() > 0)
        {
            
           int u = pq.top().second;
           pq.pop();
        
          for(auto & i : arr[u])
          {
              if(visited[i.first] > visited[u] + i.second)
              {
                  visited[i.first] = visited[u] + i.second;
                  pq.push({visited[i.first], i.first});
              }
          }
            
        }
        
        int res = 0;
        for(int i = 1; i <= n; ++i)
            res = max(res, visited[i]);
        
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends