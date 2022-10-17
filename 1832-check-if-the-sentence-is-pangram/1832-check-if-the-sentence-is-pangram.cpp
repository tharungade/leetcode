class Solution {
public:
    bool checkIfPangram(string sentence) {
        int arr[26] = {0};
        for(auto & i : sentence)
            arr[i-'a']++;
        
        for(auto & i : arr)
            if(i == 0)
                return false;
        
        return true;
    }
};