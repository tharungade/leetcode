//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    bool isValid(int x, int y, int N, int M, vector<vector<int>>& visited)
    {
        return x >= 0 && y >= 0 && x < N && y < M && !visited[x][y];
    }
    int minIteration(int N, int M, int x, int y){    
        // code here
        pair<int,int> dir[4] = {
                                {+1, 0},
                                {-1, 0},
                                {0, +1},
                                {0, -1}
                                };
        queue<pair<int,int>> q;
        vector<vector<int>> visited(N, vector<int> (M, 0));
        x--;
        y--;
        visited[x][y] = 1;
        q.push({x, y});
        int count = -1;
        while(q.size() > 0)
        {
            count++;
            int siz = q.size();
            for(int i = 0;i < siz; ++i)
            {
                auto curr = q.front();
                for(int j = 0; j < 4; ++j)
                {
                    x = curr.first + dir[j].first;
                    y = curr.second + dir[j].second;
                    if(isValid(x, y, N, M, visited))
                    {
                        visited[x][y] = 1;
                        q.push({x, y});
                    }
                }
                q.pop();
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends