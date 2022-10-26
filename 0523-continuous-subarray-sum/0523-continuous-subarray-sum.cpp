class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum = nums[0]%k, n = nums.size();
        mp[sum] = 0;
        for(int i = 1; i < n; i++)
        {
            sum = (sum + nums[i])%k;
            if(sum == 0)
                return true;
            else
            if(mp.find(sum) != mp.end())
            {
                if(i-mp[sum] > 1)
                    return true;
            }
            else
                mp[sum] = i;
        }
        
        return false;
    }
};