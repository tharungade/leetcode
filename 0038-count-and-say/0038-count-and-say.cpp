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
       string res = "1";
       for(int i = 0; i < n-1; i++)
           res = sayString(res);
        
        return res;
    }
};