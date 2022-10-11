class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMin(n), rightMax(n);
        int minInd = 0;
        for(int i = 0; i < n; i++)
        {
            leftMin[i] = minInd;
            if(nums[i] < nums[minInd])
                minInd = i;
        }
        int maxInd = n-1;
        for(int i = n-1; i >= 0; i--)
        {
            rightMax[i] = maxInd;
            if(nums[i] > nums[maxInd])
                maxInd = i;
        }
        
        for(int i = 1; i < n-1; i++)
        {
            if(nums[leftMin[i]] < nums[i] && nums[rightMax[i]] > nums[i])
                return true;
        }
        
        return false;;
    }
};