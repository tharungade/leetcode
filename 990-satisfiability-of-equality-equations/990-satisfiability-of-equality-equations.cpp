class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> arr(26,-1);
        
        for(auto & i : equations)
        {
            if(i[1] == '=')
            {
                int one = (i[0]-'a'), other = (i[3]-'a');
                while(arr[one] != -1)
                    one = arr[one];
                while(arr[other] != -1)
                    other = arr[other];
                
                if(one != other)
                    arr[one] = other;
            }
        }
        
        for(auto & i : equations)
        {
            if(i[1] == '!')
            {
                int one = (i[0]-'a'), other = (i[3]-'a');
                while(arr[one] != -1)
                    one = arr[one];
                while(arr[other] != -1)
                    other = arr[other];
                
                if(one == other)
                    return false;
            }
        }
        
        return true;
    }
};