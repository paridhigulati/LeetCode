class Solution {
public:
    
	// This function accepts height of histograms and calculates the maximum area of reactange
	// i.e this function is the solution of problem mentioned in the above link
    int maxAreaHistogram(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> rig(n, n), lef(n, -1);        // rig and lef vectors stores the first index in right and left whose height is less
        stack<int> s;
        
		// storing the right index
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && arr[s.top()]>=arr[i]) s.pop();
            
            if(!s.empty()) rig[i] = s.top();
            s.push(i);
        }
		
        while(!s.empty()) s.pop();
        
		// storing the left index
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()]>=arr[i]) s.pop();
            if(!s.empty()) lef[i] = s.top();
            s.push(i);
        }
        
        int ans = 0;
		// area =  width x height = ( rig[i] - lef[i]-1 )  x ( arr[i] )
        for(int i=0;i<n;i++)
            ans = max(ans, arr[i]*(rig[i]-lef[i]-1));
        
        return ans;
    }
    

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n==0) return 0;
        int m = matrix[0].size();
        
        vector<vector<int> > mat(n, vector<int>(m));
        
		// Converting char matrix to integer matrix
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                mat[i][j] = int(matrix[i][j]-'0');
                
		// Calculating height of histogram for each row, but note that whenever we encounter zero height will become zero
        for(int i=1;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j])
                    mat[i][j] += mat[i-1][j];

        int ans = 0;
		
		// now solving maxAreaHistogram for considering each row, and maximum of each level will be our ans
        for(int i=0;i<n;i++)
            ans = max(ans, maxAreaHistogram(mat[i]) );
        return ans;
    }
};
        
        
        
        
        
        
        
        
        
        
    