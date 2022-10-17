class Solution {
public:
    int sqSum(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += (n%10)*(n%10);
            n /= 10;
        }
        
        return sum;
    }
    bool isHappy(int n) {
         unordered_set<int> st;
        
        while(n != 1 && st.find(n) == st.end())
        {
            st.insert(n);
            n = sqSum(n);
        }
        
        return (n == 1);
    }
};