class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0, n = colors.size();
        stack<int> stk;
        for(int i = 0; i < n; i++)
        {
            if(stk.empty())
                stk.push(i);
            else
            if(colors[stk.top()] == colors[i])
            {
                if(neededTime[stk.top()] > neededTime[i])
                    res += neededTime[i];
                else
                {
                    res += neededTime[stk.top()];
                    stk.pop();
                    stk.push(i);
                }
            }
            else
            stk.push(i);
        }
        
        return res;
    }
};