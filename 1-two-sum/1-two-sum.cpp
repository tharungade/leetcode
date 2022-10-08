class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            if(mp.find(nums[i]) != mp.end())
            {
                res = {mp[nums[i]], i};
                break;
            }
            mp[target-nums[i]] = i;
        }
        
        return res;
    }
};