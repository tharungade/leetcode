class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> arr(n);
        int curr = -1;
        for(int i = n-1; i >= 0; i--)
        {
            if(dominoes[i] != '.')
                curr = i;
            arr[i] = curr;
        }
        curr = -1;
        for(int i = 0; i < n; i++)
        {
            if(dominoes[i] != '.')
                curr = i;
            if(curr == -1){
                if(arr[i] != -1 && dominoes[arr[i]] == 'L')
                    dominoes[i] = 'L';
            }
            else
            if(arr[i] == -1)
            {
                if(dominoes[curr] == 'R')
                   dominoes[i] = 'R'; 
            }
            else
            if(dominoes[curr] == dominoes[arr[i]])
                dominoes[i] = dominoes[curr];
            else
            if(dominoes[curr] != 'L')
            {
                int siz = arr[i] - curr -1, ind = i - curr;
                if(siz&1)
                {
                    if(ind != (siz+1)/2)
                    {
                        if(ind <= siz/2)
                            dominoes[i] = 'R';
                        else
                            dominoes[i] = 'L';
                    }
                }
                else
                if(ind <= siz/2)
                    dominoes[i] = 'R';
                else
                    dominoes[i] = 'L';
            }
        }
        return dominoes;
    }
};