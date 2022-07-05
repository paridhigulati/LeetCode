class Solution {
public:
    int compareVersion(string version1, string version2) {
     
        
        int i=0, j=0, c1=0, c2=0, n = version1.size(), m= version2.size();
        
        
        while(i<n or j < m)
        {
        
        while(i < n and version1[i] != '.')
        {
            c1 = c1*10 +  (version1[i]-'0');
            i++;
        }
        while(j<m and version2[j] != '.')
        {
            c2 = c2*10 + (version2[j]-'0');
            j++;
        }
        
        
        
        
        if(c1 > c2) return 1;
        
        if(c1 < c2) return -1;
            
        c1=c2=0;
            i++; j++;
        }
        return 0;
    }
};