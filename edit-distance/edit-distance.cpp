class Solution {
public:
     
        
        
        
//Recursive Solution
//Time Complexity - O (3 ^ max(a, b))
//Space Complexity - O (1)




//Bottom Up DP Solution
//Time Complexity - O (a * b)
//Space Complexity - O (a * b)

    
 
    int minDistance(string s, string t) {
        int n=s.length();
        int m=t.length();
        
        int dp[n+1][m+1];
        // filling the table from start is important here
        
        for(int i=1;i<m+1;i++){
            dp[0][i]=i;
        }
        for(int i=0;i<n+1;i++){
            dp[i][0]=i;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                
                if(s[i-1]==t[j-1]){
                    // if same they will take the value of diagonal
                    dp[i][j]=dp[i-1][j-1] ;
                }
                
                else{
                    // we will take the miniminum of operations
                        // Insert ,delete,replace
                    dp[i][j]=(1+ min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]}));
                    
                    // insert--> left
                    // delete--> above the block
                    // replace --> diagonally
                }
            }
        }
        
        return dp[n][m];
        
    }
};