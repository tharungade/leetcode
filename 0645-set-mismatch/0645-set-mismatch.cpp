class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int actualSum = n*(n+1)/2;
        int givenSum = 0;
        set<int> s;
        int alreadyThere, missing;
        for(auto & i : nums)
        {
            if(s.find(i) == s.end())
            {
                givenSum += i;
                s.insert(i);
            }
            else
                alreadyThere = i;
        }
        missing = actualSum - givenSum;
        
        return vector<int> {alreadyThere, missing};
    }
};