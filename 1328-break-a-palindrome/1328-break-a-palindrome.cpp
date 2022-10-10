class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n == 1) return "";
        
        string temp(n, 'a');
        if(temp == palindrome)
        {
             palindrome[n-1] = 'b';
            return palindrome;
        }
        int i;
        for(i = 0; i < n; i++)
            if(palindrome[i] != 'a')
                break;
        
        if(i == n/2 &&(n&1))
        {
            palindrome[n-1] = 'b';
            return palindrome;
        }
          palindrome[i] = 'a';
        
        return palindrome;
    }
};