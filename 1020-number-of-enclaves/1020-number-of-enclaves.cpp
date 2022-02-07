class Solution {
public:
//  	int rows, cols;
//  	void dfs(vector<vector<int>>& A, int i, int j) {
//  		if (i < 0 || j < 0 || i >= rows || j >= cols)
//  			return;

//  		if (A[i][j] != 1) 
//  			return;

//  		A[i][j] = -1;
//  		dfs(A, i+1, j);
//  		dfs(A, i-1, j);
//  		dfs(A, i, j+1);
//  		dfs(A, i, j-1);
//  	}
//  public:
//  	int numEnclaves(vector<vector<int>>& A) {


//  		rows = A.size();
//  		cols = A[0].size();
//  		for (int i = 0; i < rows; i++) {
//  			for (int j = 0; j < cols; j++) {
//  				if (i == 0 || j == 0 || i == rows-1 || j == cols-1)
//  					dfs(A, i, j);
//  			}
//  		}

//  		int ans = 0;
//  		for (int i = 0; i < rows; i++) {
//  			for (int j = 0; j < cols; j++) {
//  				if (A[i][j] == 1)
//  					ans++;
//  			}
//  		}

//  		return ans;
//  	}
//  };

























void dfs(int i,int j, vector<vector<int>> &A)
{
    if(i<0 || i>= A.size() || j<0 || j>=A[0].size())
        return;
    if(A[i][j] != 1) return;
    A[i][j] = '#';
    dfs(i-1,j,A);
    dfs(i+1,j,A);
    dfs(i,j-1,A);
    dfs(i,j+1,A);
}







int numEnclaves(vector<vector<int>>& A) {
    
 
    int m = A.size();
    int n =  A[0].size();
    for( int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 || i==m-1 || j==0||j==n-1)
                dfs(i,j,A);
        }
    }
       int count=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j] == 1)
                count++;
        
        }
    }
    return count;
}
};
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

