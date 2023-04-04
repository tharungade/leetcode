//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int low = 0, high = str.size()-1;
    int count = 0;
    if(str[low] != str[high])
    {
        count++;
        while(low <= high && str[low] != str[high])
        {
            high--;
        }
    }
    
    while(low <= high)
    {
        char curr = str[low];
        while(low <= high && str[low] == curr)
        {
            low++;
        }
        while(low <= high && str[high] == curr)
        {
            high--;
        }
        count++;
    }
    
    return count;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends