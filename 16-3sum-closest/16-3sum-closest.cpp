class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), res = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++)
        {
            int low = i + 1, high = n-1;
            while(low < high)
            {
                if(abs(target-(nums[i]+nums[low]+nums[high])) < abs(res))
                    res = target-(nums[i]+nums[low]+nums[high]);
                if(target < nums[i]+nums[low]+nums[high])
                    high--;
                else
                    low++;
            }
        }
        
        return (target-res);
    }
};