class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*  brute/better approach 
         this approach works fine when it is given only rows and only columnws are sorted(gfg) but here the  whole matrix is sorted so we can simply apply binary search 
        
        
        
        int i =0;
        int j = matrix[0].size()-1;
        while(i<matrix[0].size() && j>=0)
        {
            if(matrix[i][j]==target)
            {
                return true;
            }
          
                if(matrix[i][j]> target)
                    j--;
            else
             i++;
        }
      return false; */
    
    
    //TIME COMPLEXITY = LOG(MN),  O(1)
    
        if(matrix.size()==0)
            return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int low =0;
        int high = (n*m)-1;
    while(low <=high)
    {
        int mid = (low) + (high-low)/2;
        if(matrix[mid/m][mid%m]==target)
            return true;
        if(matrix[mid/m][mid%m]<target)
            low = mid+1;
        else
            high = mid-1;
    
    }
    return false;    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    }
    
    
};