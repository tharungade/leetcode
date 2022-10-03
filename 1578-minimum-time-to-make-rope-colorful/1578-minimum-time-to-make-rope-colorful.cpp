class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0, j = 0, res = 0, n = colors.size(), currTotal, maxTime;
        
        while(i < n && j < n)
        {
            currTotal = 0;
            maxTime = 0;
            while(j < n  &&  colors[i] == colors[j])
            {
                currTotal += neededTime[j];
                maxTime = max(maxTime, neededTime[j]);
                j++;
            }
            
            res += (currTotal-maxTime);
            i = j;
        }
        
        return res;
    }
};