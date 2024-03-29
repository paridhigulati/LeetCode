/* to find length of longest substring
            if(dp[i][j])
                count = g+1; // to give length of longest palind substring 
    
*/
class Solution {
public:
     string longestPalindrome(string s) 
{   
    int len = s.size();
    int dp[len][len];
    memset(dp,0,sizeof(dp));
    int end=1;
    int start=0;
	
    for(int i=0;i<len;i++)
    {
        dp[i][i] = 1;
    }
    for(int i=0;i<len-1;i++)
    {
        if(s[i]==s[i+1])
        { dp[i][i+1]=1;start=i;end=2;}
    }
    
    for(int j=2;j<len;j++)
    {
        for(int i=0;i< len-j;i++)
        {  
            int left=i; //start point
            int right = i+j;  //ending point
            
            if(dp[left+1][right-1]==1 && s[left]==s[right]) 
            {
                dp[left][right]=1; start=i; end=j+1; 
            }        
        }
    }
   return s.substr(start, end);
}
};