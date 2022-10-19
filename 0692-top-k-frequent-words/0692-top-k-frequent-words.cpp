class myComparator
{
public:
    int operator() (const pair<int,string> &c1,const pair<int,string> &c2)
    {
        if(c1.first == c2.first)
            return c1.second < c2.second;
        return c1.first > c2.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        priority_queue< pair<int,string>, vector<pair<int,string>>, myComparator > minHeap;
        
        unordered_map<string, int> mp;
        for(auto & i : words) mp[i]++;
        
       for(auto & i : mp)
       {
           minHeap.push({i.second, i.first});
           if(minHeap.size() > k)
               minHeap.pop();
       }
        
        while(minHeap.size() > 0)
        {
            res.insert(res.begin(), minHeap.top().second);
            minHeap.pop();
        }
        
        return res;
    }
};