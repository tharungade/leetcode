//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  bool sign(int n)
  {
      if(n < 0)
        return 1;
      return 0;
  }
  long long int wineSelling(vector<int>& Arr, int N){
      //Code here.
      queue<pair<int,int>> q;
      long long res = 0;
      for(int i = 0; i < N; ++i)
      {
          
          if(Arr[i] != 0)
          {
              if(q.empty() || sign(Arr[i]) == sign(q.front().first))
                q.push({Arr[i], i});
              else
              {
                  int temp = Arr[i];
                  while(q.size() > 0 && abs(temp) > 0)
                  {
                      if(abs(q.front().first) <= abs(temp))
                      {
                          res += abs(q.front().first)*(i-q.front().second);
                          temp += q.front().first;
                          q.pop();
                          
                      }
                      else
                      {
                          res += abs(temp)*(i-q.front().second);
                          q.front().first += temp;
                          temp = 0;
                      }
                  }
                  if(q.size() == 0 && abs(temp) > 0)
                    q.push({temp, i});
              }  
          }
      }
      return res;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends