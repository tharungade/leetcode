class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int n = nums.size();
        vector<pair<int,int>> arr(n);
        for(int i = 0 ; i < n; i++)
        {
            arr[i].first = nums[i];
            arr[i].second = i;
        }
        sort(arr.begin(), arr.end());
        int low = 0, high = n-1, currSum;
        while(low < high)
        {
            currSum = arr[low].first + arr[high].first;
            if(currSum == target)
            {
                res = {arr[low].second, arr[high].second};
                break;
            }
            if(currSum < target)
                low ++;
            else
                high--;
        }
        return res;
    }
};