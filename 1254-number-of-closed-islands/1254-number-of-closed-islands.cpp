class Solution {
public:
     
 /*   
  Approach-We apply dfs on boundary and mark all boundary Os and its connected components as -1(to recognize they are visited). Now,the matrix consists of only those Os that are surrounded by water.So, we perform dfs on the matrix and find the number of connected components.*/

//same as no. of enclaves 
    // void dfs(int i,int j,vector<vector<int>>& grid){
    //     int m=grid.size(),n=grid[0].size();
    //     if(i<0 ||i>m-1 || j<0 || j>n-1 || grid[i][j]!=0) return;
    //     grid[i][j]=-1;
    //     dfs(i-1,j,grid);
    //     dfs(i,j-1,grid);
    //     dfs(i+1,j,grid);
    //     dfs(i,j+1,grid);
    // }

//         int m=grid.size(),n=grid[0].size(),ans=0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if((i==0||j==0||i==m-1||j==n-1)&&grid[i][j]==0){
//                     dfs(i,j,grid);

//                 }
//             }
//         }
//            for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==0){
//                     dfs(i,j,grid);
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };


void dfs(int i,int j, vector<vector<int>> &A)
{
    if(i<0 || i>= A.size() || j<0 || j>=A[0].size())
        return;
    if(A[i][j] != 0) return;
    A[i][j] = -1;
    dfs(i-1,j,A);
    dfs(i+1,j,A);
    dfs(i,j-1,A);
    dfs(i,j+1,A);
}

    int closedIsland(vector<vector<int>>& A) {

    
 
    int m = A.size();
    int n =  A[0].size();
    for( int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 || i==m-1 || j==0||j==n-1 and A[i][j]==0)
                dfs(i,j,A);
        }
    }
       int count=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j] == 0)
            {
                dfs(i,j,A);
                count++;
            }
        
        }
    }
    return count;
}
};
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    