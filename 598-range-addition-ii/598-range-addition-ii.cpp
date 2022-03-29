class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        
        int minRow = m, minCol = n;
    
        
        for(auto i : ops)
        {
            minRow = min(minRow, i[0]);
            minCol= min(minCol, i[1]);
        }
        return minRow * minCol;
    }
};