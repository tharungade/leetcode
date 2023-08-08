//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    int helperBinarySearch(int target, int low, vector<pair<long int, long int>> &arr)
    {
        long int l = low, h = arr.size() - 1, leftMost = -1;
        long int num = (arr[target].second-arr[target].first), den = arr[target].second;
        while(l <= h)
        {
            int mid = l + (h-l)/2;
            if(arr[mid].first * den == arr[mid].second * num)
            {
                leftMost = mid;
                h = mid - 1;
            }
            else
            if(arr[mid].first * den > arr[mid].second * num)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if(leftMost == -1)
        {
            return 0;
        }
        l = leftMost, h = arr.size() - 1;
        long int rightMost = leftMost;
        while(l <= h)
        {
            int mid = l + (h-l)/2;
            if(arr[mid].first * den == arr[mid].second * num)
            {
                rightMost = mid;
                l = mid + 1;
            }
            else
            if(arr[mid].first * den > arr[mid].second * num)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return rightMost - leftMost + 1;
    }
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        vector<pair<long int, long int>> arr;
        for(int i = 0; i < n; ++i)
        {
            arr.push_back({numerator[i], denominator[i]});
        }
        sort(arr.begin(), arr.end(), [](auto& a, auto &b)
        {
           return (long int)a.first * b.second < (long int)a.second * b.first; 
        });
        int count = 0;
        for(int i = 0; i < n; ++i)
        {
            if(arr[i].first > arr[i].second)
            {
                break;
            }
            count += helperBinarySearch(i, i + 1, arr);
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
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends