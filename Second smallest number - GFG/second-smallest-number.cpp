//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        // code here 
        if(S/9 + (S%9?1:0) > D || D == 1|| S == 1)
        {
            return "-1";
        }
        string res = "";
        for(int i = 1; i <= D; ++i)
        {
            if(S == 1)
            {
                res += "0";
            }
            else
            {
                int add = (S > 9)?9: S-1;
                res += (char)('0' + add);
                S -= add;
            }
        }
        if(S > 1 || res[D-1] == '9')
        {
            return "-1";
        }
        int lastDigit = res[D-1] - '0';
        res.pop_back();
        res += (char)(lastDigit +1+'0');
        
        bool flag = true;
        for(int i = 0; i < D-1; ++i)
        {
            if(res[i] > res[i+1])
            {
                res[i] = (char)(res[i]-1);
                res[i+1] = (char)(res[i+1]+1);
                flag = false;
                break;
            }
        }
        if(flag)
        {
            return "-1";
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends