class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        vector<vector<string>> res;
        
        for(auto & i : strs)
        {
            vector<int> freqCount(26,0);
            for(auto & j : i)
                freqCount[j-'a']++;
            
            mp[freqCount].push_back(i);
        }
        
        for(auto & i : mp)
            res.push_back(i.second);
        
        
        return res;
    }
};