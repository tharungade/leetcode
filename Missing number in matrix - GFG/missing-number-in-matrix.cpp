//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long int MissingNo(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size(), m = matrix[0].size(),zeroI = -1,zeroJ = -1;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    zeroI = i;
                    zeroJ = j;
                    break;
                }
            }
            if(zeroI != -1)
                    break;
        }
        
        unordered_set<long long> st;
        
        for(int i = 0; i < n; ++i)
        {
            if(i == zeroI)
                continue;
            long long sum = 0;
            for(int j = 0; j < m; ++j)
            {
               sum += matrix[i][j];
            }
            st.insert(sum);
            if(st.size() > 1)
                return -1;
        }
        
        long long sumI = 0, sumJ = 0, diagonal1 = 0, diagonal2 = 0;
        for(int j = 0; j < m; ++j){
            sumI += matrix[zeroI][j];
            diagonal1 += matrix[j][j];
        }
        for(int i = 0; i < n; ++i){
            sumJ += matrix[i][zeroJ];
            diagonal2 += matrix[i][n-i-1];
        }
        if(sumI != sumJ || sumI >= *(st.begin()))
            return -1;
            
        if(zeroI == zeroJ)
        {
            if(diagonal1 != sumI)
                return -1;
        }
        else
        {
            if(diagonal1 != *(st.begin()))
                return -1;
        }
        
        if(zeroI == n-zeroJ-1)
        {
            if(diagonal2 != sumI)
                return -1;
        }
        else
        {
            if(diagonal2 != *(st.begin()))
                return -1;
        }
        
        return (*(st.begin()) - sumI);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends