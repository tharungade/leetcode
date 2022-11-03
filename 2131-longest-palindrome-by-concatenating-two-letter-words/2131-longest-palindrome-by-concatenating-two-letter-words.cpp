class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        string currRes;
        
        for(auto & i : words)
           mp[i]++;
        
        bool oddSamePal = false;
        int res = 0;
        // for(auto & i : mp)
        //     cout << i.first << " " << i.second << endl;
        for(auto & i : mp)
        {
            currRes = i.first;
            reverse(currRes.begin(), currRes.end());
            if(i.first == currRes){
               if(i.second & 1)
                oddSamePal = true;
            
                res += (i.second/2)*2;
            }
            else
            if(mp.find(currRes) != mp.end()){
                res += min(i.second , mp[currRes])*2;
                mp[i.first] = 0;
            }
        }
        if(oddSamePal) res++;
        
        return res*2;
    }
};