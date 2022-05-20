class Solution {
public:
    int strStr(string haystack, string needle) {
     
        int n = haystack.size(), m = needle.size();
        
        if(m==0) return 0;
        for(int i=0;i<=n-m;i++)
        {
            int j = 0;
            for( j=0;j<m;j++)
            {
                if(haystack[j+i]  != needle[j])
                  break;
            }
            if(j==m) return i;
        }
        
        return -1;
    }
};