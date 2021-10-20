class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      
        vector<vector<int>> v(numRows);
        
        for(int i =0; i<numRows;i++){
            v[i].resize(i+1); // if i==0 we need one shell if 1 then 2
            
            v[i][0] = 1;//first element of row i
            
            v[i][i] = 1; // last element of row i
            
            for(int j = 1;j<i;j++){
                v[i][j] = v[i-1][j]+v[i-1][j-1];
            }
            
            
        }
        return v;
    }
};