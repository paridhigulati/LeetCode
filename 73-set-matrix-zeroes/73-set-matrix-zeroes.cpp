class Solution {
public:
       
           void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
                /*step 1 make dummy array 
        vector<int>row(n,1);
        vector<int>col(m,1); */
        
        bool frow = false;
        bool fcol = false;
        //to handle first row and first col 
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]==0)
                fcol = true;
        }
           for(int j=0;j<m;j++)
            {
                if(matrix[0][j]==0)
                {
                    frow=true;
                }
           }
 // step 2 : rest of array 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                        matrix[0][j]=0;
                }
            }
        }
               //now from 1st row and col check if 0th row/col is 0 
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }
        if(fcol)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][0]=0;
            }
        }
        if(frow)
        {
            for(int j=0;j<m;j++)
            {
                matrix[0][j]=0;
            }
        }
    }
};
//Time Complexity : O(M×N)
//Space Complexity : O(1)
