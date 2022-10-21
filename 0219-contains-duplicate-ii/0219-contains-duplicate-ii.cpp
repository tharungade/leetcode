class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;
        k++;
        for(int i = 0; i < min(k,(int)nums.size()); i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] > 1)
                return true;
        }
        
        for(int i = k; i < nums.size();i++)
        {
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            if(mp[nums[i]] > 1)
                return true;
        }
        
        return false;
    }
};