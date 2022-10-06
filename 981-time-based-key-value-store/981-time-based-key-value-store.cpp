class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> arr;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        arr[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
       string res = "";
       if(arr.find(key) != arr.end())
       {
           int low = 0,high = arr[key].size()-1;
           while(low <= high)
           {
               int mid = low + (high - low)/2;
               if(arr[key][mid].first <= timestamp)
               {
                   res = arr[key][mid].second;
                   low = mid+1;
               }
               else
               high = mid - 1;
           }
       }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */