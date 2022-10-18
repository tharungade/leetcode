class Solution {
public:
    string sayString(string str)
    {
        string res = "";
        int n = str.size();
        int i = 0, j = 0;
        while(j < n)
        {
            while(j < n && str[i] == str[j])
                j++;
            res += to_string(j-i);
            res += str[i];
            i = j;
        }
        
        return res;
    }
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        
        return sayString(countAndSay(n-1));
    }
};