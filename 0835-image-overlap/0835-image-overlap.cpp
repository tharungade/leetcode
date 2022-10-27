class Solution {
public:
    int func(vector<vector<int>>& img1, vector<vector<int>>& img2,int row, int col, bool rowInc, bool colInc)
    {
        int res = 0, n = img1.size();
        
        for(int i = row; i < n; i++)
        {
            for(int j = col; j < n; j++)
            {
                if(rowInc)
                {
                    if(colInc)
                        res += (img1[i-row][j-col] && img2[i][j]);
                    else
                        res += (img1[i-row][j] && img2[i][j-col]);
                }
                else
                {
                    if(colInc)
                        res += (img1[i][j-col] && img2[i-row][j]);
                    else
                        res += (img1[i][j] && img2[i-row][j-col]);
                }   
            }
        }
        
        return res;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(),  res = 0;
        // true --> positive movement of img1
        // false --> negative movement of img1
        // moving down
        for(int down = 0; down < n; down++)
        {
            // move right
            for(int right = 0; right < n; right++)
                res = max(res, func(img1, img2, down, right, true, true));
            //move left
            for(int left = 1; left < n; left++)
                res = max(res, func(img1, img2, down, left, true, false));
        }
        
        // moving up
        for(int up = 1; up < n; up++)
        {
            // move right
            for(int right = 0; right < n; right++)
                res = max(res, func(img1, img2, up, right, false, true));

            //move left
            for(int left = 1; left < n; left++)
                res = max(res, func(img1, img2, up, left, false, false));
        }
        
        
        return res;
    }
};