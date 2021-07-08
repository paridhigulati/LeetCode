
 /*   int minDistance(string word1, string word2) {
      
     return solve(word1, word2, 0, 0);
}
// recursive solver to find minimum deletions to equalize w1 & w2
int solve(string w1, string w2, int i, int j) {
	if(i == size(w1) && j == size(w2)) 
        return 0;  // reached end of both strings -> both strings have been equalized and no further steps required
	if(i == size(w1))
        return size(w2) - j;        // reached end of word1 -> need to delete remaining characters of word2 to equalize
    if(j == size(w2)) 
        return size(w1) - i;        // reached end of word2 -> need to delete remaining characters of word1 to equalize
	if(w1[i] == w2[j]) 
        return solve(w1, w2, i + 1, j + 1);  // no deletion required since the characters already match
	// 1 current character deletion + min(after deleting w1[i], after deleting w2[j])
	return 1 + min(solve(w1, w2, i + 1, j), solve(w1, w2, i, j + 1));
}
    
};

*/

/* intuition
We can see that for an index i, j of word1 and word2, we have following cases -

  1. word1[i] == word2[j] : The characters match and there's no need of deletion. Move on to next character of both words

  2. word1[i] != word2[j] : The characters don't match. We only have two choices if we want to equalize the words. Either -

    I. delete word1[i].
    II. delete word2[j].

  3. i == word1.length and j == word2.length : We have reached end of both words and both strings have been equalized. No further steps needed.

  4. i == word1.length OR j == word2.length : We have reached end of one word and only way to equalize is to delete rest of characters of the other word.

This can be easily implemented as a recursive function. Also, we don't need to explicitly delete any characters of the words. We will just denote deleting word1[i] (case 2.I) by recursing for (i+1)th index and deleting word2[j] (case 2.II) by recursing for (j + 1)th index. */


//USING LCS 
class Solution {
public:
    
int lcs(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++)
        dp[i][0]=0;
    for(int i=0;i<m+1;i++)
        dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]= 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
     
}  

  int minDistance(string word1, string word2)
  {
   int lcsLen = lcs(word1,word2);
  return word1.size() + word2.size() - 2*lcsLen;
  }
};