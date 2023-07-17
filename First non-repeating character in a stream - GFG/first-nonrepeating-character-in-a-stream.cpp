//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int> charCount(26, 0);
		    string result = "";
		    int sizeOfA = A.size();
		    int nonRepeatingPointer = 0;
		    for(int iterator = 0; iterator < sizeOfA; ++iterator)
		    {
		       charCount[A[iterator]-'a']++;
		       while(nonRepeatingPointer <= iterator && charCount[A[nonRepeatingPointer]-'a'] > 1)
		       {
		           nonRepeatingPointer++;
		       }
		       if(nonRepeatingPointer <= iterator)
		       {
		           result += A[nonRepeatingPointer];
		       }
		       else
		       {
		           result += '#';
		       }
		    }
		    
		    return result;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends