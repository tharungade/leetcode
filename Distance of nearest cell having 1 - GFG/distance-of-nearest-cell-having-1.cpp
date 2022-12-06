//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    pair<int,int> dir[4] = 
    {
        {-1,0},
        {+1,0},
        {0,-1},
        {0,+1}
    };
    bool isSafe(int i, int j, int n, int m, vector<vector<int>> &res)
    {
        return i >= 0 && j >= 0 && i < n && j < m && res[i][j] == -1;
    }
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>> nearest(vector<vector<int>> &grid)
	{
	    // Code here
	    int n = grid.size(), m = grid[0].size();
	    vector<vector<int>> res(n, vector<int> (m, -1));
	    
	    queue<pair<int,int>> q;
	    
	    for(int i = 0; i < n; ++i)
	    {
	        for(int j = 0; j < m; ++j)
	        {
	            if(grid[i][j] == 1)
	            {
	                res[i][j] = 0;
	                q.push({i,j});
	            }
	        }
	    }
	    
	    int i, j, count = 0;
	    
	   // while(q.size() > 0)
	   // {
	   //     cout << q.front().first << " " << q.front().second << endl;
	   //     q.pop();
	   // }
	    
	    while(q.size() > 0)
	    {
	        int siz = q.size();
	        count++;
	        for(int k = 0; k < siz ; ++k)
	        {
	            i = q.front().first;
	            j = q.front().second;
	            
	            for(int t = 0; t < 4; ++t)
	            {
	                if(isSafe(i+dir[t].first,j+dir[t].second,n,m,res))
	                {
	                    res[i+dir[t].first][j+dir[t].second] = count;
	                    q.push({i+dir[t].first, j+dir[t].second});
	                }
	            }
	           // cout << q.front().first << " " << q.front().second << endl;
	            q.pop();
	        }
	    }
	    
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends