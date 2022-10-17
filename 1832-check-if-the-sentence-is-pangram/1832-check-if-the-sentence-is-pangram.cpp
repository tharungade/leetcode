class Solution {
public:
    bool checkIfPangram(string sentence) {
        int stor = 0;
        for(auto & i : sentence)
            stor = stor | (1 << (i-'a'));
        
        return stor + 1 == (1 << 26);
    }
};