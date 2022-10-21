class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        k++;
        for(int i = 0; i < min(k, (int)nums.size()); i++)
        {
            if(st.find(nums[i]) != st.end())
                return true;
        
            st.insert(nums[i]);
        }
        
        for(int i =k; i < nums.size(); i++)
        {
            st.erase(st.find(nums[i-k]));
            if(st.find(nums[i]) != st.end())
                return true;
            
            st.insert(nums[i]);
        }
        
        return false;
    }
};