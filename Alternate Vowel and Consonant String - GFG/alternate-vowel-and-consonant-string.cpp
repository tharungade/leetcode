//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    bool isVowel(char &ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    string rearrange (string S, int N)
    {
        // your code here
        vector<int> vowels(26, 0), consonents(26, 0);
        int vowelsCount = 0, consonentsCount = 0;
        for(auto & i : S)
        {
            if(isVowel(i)){
                vowels[i-'a']++;
                vowelsCount++;
            }
            else{
                consonents[i-'a']++;
                consonentsCount++;
            }
        }
        
        if(abs(vowelsCount-consonentsCount) > 1)
            return "-1";
            
        string res = "";
        bool vowel = false;
        if(vowelsCount == consonentsCount)
        {
            for(int i = 0; i < 26; i++)
            {
                if(vowels[i] != 0){
                    vowel = true;
                    break;
                }
                if(consonents[i] != 0){
                    vowel = false;
                    break;
                }
            }
        }
        else
        if(vowelsCount > consonentsCount)
            vowel = true;
        
        int i = 0, j= 0;  
        while(i < 26 || j < 26)
        {
            if(vowel)
            {
                while(i < 26 && vowels[i] == 0)
                i++;
                if(i < 26){
                    res += ('a' + i);
                    vowels[i]--;
                }
            }
            else{
                while(j < 26 && consonents[j] == 0)
                    j++; 
                if(j < 26){
                    res += ('a' + j);
                    consonents[j]--;
                }
            }
            vowel = !vowel;
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends