class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMin(n);
        int minInd = 0;
        for(int i = 0; i < n; i++)
        {
            leftMin[i] = minInd;
            if(nums[i] < nums[minInd])
                minInd = i;
        }
        int maxInd = n-1;
        for(int i = n-2; i >= 0; i--)
        {
            if(nums[leftMin[i]] < nums[i] && nums[maxInd] > nums[i])
                return true;
            
            if(nums[i] > nums[maxInd])
                maxInd = i;
        }
        
        return false;;
    }
};