class Solution {
public:
    bool mutation(string &s1, string &s2)
    {
        int count = 0, n = s1.size();
        for(int i = 0; i < n; i++)
        {
            if(s1[i] != s2[i])
                count++;
            if(count > 1)
                return false;
        }
        
        return count == 1;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<pair<string,string>, int>> q; // string parent no.ofsteps
        
        q.push({{start,""}, 0});
        
        while(q.size() > 0)
        {
            auto curr = q.front();
            if(curr.first.first == end)
                return curr.second;
            
            for(auto & i : bank)
            {
                if(i != curr.first.second && mutation(curr.first.first, i))
                    q.push({{i,curr.first.first}, curr.second + 1});
            }
            
            q.pop();
        }
        
        return -1;
    }
};