class Solution 
{
public:
    /* find LCS between the strings and check if LCS value == length of the first string. 

 bool isSubsequence(string s, string t) {
      int n=s.size(),m=t.size() ;
      int dp[n+1][m+1];
for(int i=0;i<=n;i++)
{
for(int j=0;j<=m;j++)
{
if(i==0 || j==0)
dp[i][j]=0;
else if(s[i-1]==t[j-1])
dp[i][j]=1+dp[i-1][j-1];
else
dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
}
}
if(dp[n][m]==n)
return true;
else
return false;
}
};
USING 2 POINTERS 
    The approach is simple to undertsand. You just have to take two pointers for the two strings. If the character of string s doesn't match with that of string t, you have to increment the pointer of t. If the character matches, increment the pointer for both the strings. At the end, if the pointer reaches the end, return true, else return false.*/


    bool isSubsequence(string s, string t) {
        if(s.size()>t.size())return false;
        int i=0,j=0;
        while(i<s.size()&&j<t.size()){
            if(s[i]==t[j]){i++;j++;}
            else{j++;}
        }
        return i==s.size()?true:false;
    }
};