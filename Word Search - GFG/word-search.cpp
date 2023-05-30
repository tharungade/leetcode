//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isValid(int i, int j, vector<vector<char>>& board)
    {
        return i >= 0 && j >= 0 && i < board.size() && j < board[0].size();
    }
    
    bool helper(int ind, int i ,int j, vector<vector<char>>& board, string &word)
    {
        if(board[i][j] != word[ind])
        {
            return false;
        }
        if(ind == word.size()-1)
        {
            return true;
        }
        char stor = board[i][j];
        board[i][j] = '$';
        bool down = false, up = false, right = false, left = false;
        if(isValid(i +1 , j, board))
        {
            down = helper(ind + 1, i + 1, j , board, word);
        }
        if(isValid(i , j + 1, board))
        {
            right = helper(ind + 1, i , j + 1 , board, word);
        }
        if(isValid(i - 1 , j, board))
        {
            up = helper(ind + 1, i - 1, j , board, word);
        }
        if(isValid(i ,j - 1, board))
        {
            left = helper(ind + 1, i, j - 1, board, word);
        }
        board[i][j] = stor;
        
        return up || down || right || left;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n = board.size(), m = board[0].size();
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(helper(0, i, j, board, word))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends