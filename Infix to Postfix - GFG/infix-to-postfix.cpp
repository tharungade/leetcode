//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int precedence(char ch)
    {
        if(ch == '^')
            return 3;
        if(ch == '*' || ch == '/')
            return 2;
        if(ch == '+' || ch == '-')
            return 1;
        if(ch == '(')
            return 0;
    }
    bool isOperator(char ch)
    {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
    }
    string infixToPostfix(string s) {
        // Your code here
        stack<char> stk;
        string res = "";
        for(auto & i : s)
        {
            if(isOperator(i))
            {
                while(stk.size() > 0 && precedence(stk.top()) >= precedence(i))
                {
                    res += stk.top();
                    stk.pop();
                }
                stk.push(i);
            }
            else
            if(i == '(')
                stk.push(i);
            else
            if(i == ')')
            {
                while(stk.top() != '(')
                {
                    res += stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            else
                res += i;
        }
        while(stk.size() > 0)
        {
            res += stk.top();
            stk.pop();
        }
        
        return res;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends