//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool shouldChangeToQuestionMark(int ind, string &s)
    {
       return (s[ind] != '?') && ((ind-1 >= 0 && s[ind-1] != '?' && s[ind] == s[ind-1]) ||
              (ind + 1 < s.size() && s[ind+1] != '?' && s[ind] == s[ind+1]));
    }
    int getMinimumDays(int N,string &S, vector<int> &P) {
        // code here
        int recentUpdatedDay = 0;
        for(int i = 0; i < N; ++i)
        {
            if(shouldChangeToQuestionMark(P[i], S))
            {
                S[P[i]] = '?';
                recentUpdatedDay = i + 1;
            }
        }
        
        return recentUpdatedDay;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends