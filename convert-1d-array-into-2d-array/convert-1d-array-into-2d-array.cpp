class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {     
        if(m * n != original.size()) // all elements can't be placed in grid of size (m x n)
            return {};
        vector<vector<int>> res(m , vector<int>(n));
        int a = 0 , b = 0; // a is row pointer , b is col pointer
        
        for(int ele : original)
        {
            res[a][b] = ele;
            ++b;
            if(b == n) // if row is filled move to next row
                b = 0 , ++a;
        }
        return res;
    }
};      
 