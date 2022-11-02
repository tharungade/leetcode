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
       queue<pair<string,int>> q;
       unordered_set<string> s;
        
       q.push({start, 0});
       s.insert(start);
       while(q.size() > 0)
       {
           auto curr = q.front();
           
           if(curr.first == end)
               return curr.second;
           
           for(auto & i: bank)
           {
               if(s.find(i) == s.end() && mutation(curr.first, i)){
                   q.push({i, curr.second + 1});
                   s.insert(i);
               }
           }
           
           q.pop();
       }
    
        return -1;
    }
};