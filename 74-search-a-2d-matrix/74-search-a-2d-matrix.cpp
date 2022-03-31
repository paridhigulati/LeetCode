class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
      
        int m = matrix.size(), n = matrix[0].size();
        
            // if(matrix.size()==0)
            // return false;
//             int low = 0, high = (n*m)-1;
//             while(low <= high)
//             {
//                 int mid = low + (high-low)/2;
                
//                 if(matrix[mid/n][mid%n] == target)
//                     return true;
                
//                 else if(matrix[mid/n][mid%n]  > target)
//                     high = mid-1;
//                 else 
//                     low = mid+1;
                
//             }
        
//         return false;
        
        //O(M+N) 2pointer
        int i=0, j= n-1;
        while(i < m and j>=0)
        {
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target )
                j--;
            else
                i++;
        }
        return false;
    }
};