class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>row(n,1);
        vector<int>col(m,1);
        // step 1 make dummy array 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    //if u find 0 in matrix,change the value of cell to zero in corresponding col and row
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        //now we need to change the 1s in matrix to zero so!
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
            if(row[i]==0|| col[j]==0)
            {
             
                    matrix[i][j]=0;
            }
        }
        }
        /*
         for(int j=0;j<m;j++)
         {
             if(col[j]==0)
             {
                  for(int i=0;i<n;i++)
                  {
                      matrix[i][j]=0;
                    }
               }
         }
         */
     
    }
};