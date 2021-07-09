
    /*string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        // fill the dp table
        int dp[m + 1][n + 1];
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        string ans;
        int i = m, j = n;
        while(i > 0 && j > 0)
        {
            // If current character in both the strings are same, then current character is part of shortest supersequence
            if(str1[i - 1] == str2[j - 1])
            {
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            // If current character in X and Y are different & we are moving upwards
            else if(dp[i - 1][j] > dp[i][j - 1])
            {
                ans.push_back(str1[i - 1]);
                i--;
            }
            // If current character in X and Y are different & we are moving leftwards
            else
            {
                ans.push_back(str2[j - 1]);
                j--;
            }
        }
        // If str2 reaches its end, put remaining characters of str1 in the result string
        while(i > 0)
        {
            ans.push_back(str1[i - 1]);
            i--;
        }
        // If str1 reaches its end, put remaining characters of str2 in the result string
        while(j > 0)
        {
            ans.push_back(str2[j - 1]);
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
}; */
    class Solution {  //techdose 
        public:
    string findLCS(string str1,string str2)
    {
        int len1 = str1.size();
        int len2 = str2.size();
        string dp[len1+1][len2+1];
        
        for(int i=0;i<=len1;++i)
            for(int j=0;j<=len2;++j)
            {
                if(i==0 || j==0)
                    dp[i][j] = "";
                else if(str1[i-1]==str2[j-1])
                    dp[i][j] = dp[i-1][j-1]+str1[i-1];
                else
                    dp[i][j] = dp[i][j-1].size() > dp[i-1][j].size() ? dp[i][j-1]:dp[i-1][j];
            }
        return dp[len1][len2];
    }

    string shortestCommonSupersequence(string str1, string str2) {
        string ans = "";
        string lcs = findLCS(str1,str2);
        
        int p1=0,p2=0;
        for(char c: lcs)
        {
            while(str1[p1]!=c)  //Add all non-LCS chars from str1
                ans += str1[p1++];
            while(str2[p2]!=c)  //Add all non-LCS chars from str2
                ans += str2[p2++];
            
            ans += c;   //Add LCS-char and increment both ptrs
            ++p1;
            ++p2;
        }
        ans += str1.substr(p1) + str2.substr(p2);
        return ans;
    }
};