class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int word1Ind = 0, ind1 = 0, word2Ind = 0, ind2 = 0;
        int word1Size = word1.size(), word2Size = word2.size();
        
        while(word1Ind < word1Size && word2Ind < word2Size)
        {
            if(word1[word1Ind][ind1] != word2[word2Ind][ind2])
                return false;
            ind1++;
            ind2++;
            if(ind1 >= word1[word1Ind].size())
            {
                ind1 = 0;
                word1Ind++;
            }
            
            if(ind2 >= word2[word2Ind].size())
            {
                ind2 = 0;
                word2Ind++;
            }
        }
        
        if(word1Ind < word1Size || word2Ind < word2Size)
            return false;
        
        return true;    
    }
};