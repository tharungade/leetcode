//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool valid(int r, int c,int n, int m, int currDir, pair<int, int> add[])
    {
        r = r + add[currDir].first;
        c = c + add[currDir].second;
        
        return r >= 0 && c >= 0 && r < n && c < m;
    }
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        // 0->right 1 ->down 2->left 3->up
        int n = matrix.size(), m = matrix[0].size();
        int currDir = 0;
        int arr[4] = { 1, 2, 3, 0 };
        pair<int, int> add[4] = 
        {
          {0,+1}, // right
          {+1,0}, // down
          {0,-1}, // left
          {-1,0} // up
        };
        
        int r = 0, c= 0;
        while(true)
        {
            if(matrix[r][c] == 1){
                matrix[r][c] = 0;
                currDir = arr[currDir];
            }
            
            if(valid(r, c,n ,m, currDir, add))
            {
                r = r + add[currDir].first;
                c = c + add[currDir].second;
            }
            else
                break;
        }
        
        return {r, c};
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends