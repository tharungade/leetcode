//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    // Code here
	    vector<int> arr;
	    if(N%2 == 0)
	    {
	        arr.push_back(2);
	        while(N%2 == 0)
	            N /= 2;
	    }
	    int factor = 3;
	    while(N > 1 && factor*factor <= N)
	    {
	        if(N%factor == 0)
	        {
	            arr.push_back(factor);
	            while(N%factor == 0)
	                N /= factor;
	        }
	        factor += 2;
	    }
	    if(N != 1)
	    arr.push_back(N);
	    
	    return arr;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends