class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
     
        
        
        int i=0,j=0;
        vector<int>hash(26,0);
        vector<int>pattern(26,0);
        int k = p.size();
        int n = s.size();
        
        vector<int>res;
        
        for(char ch : p)
        {
            pattern[ch-'a']++;
        }
        
        while(j < n)
        {
          hash[s[j] -'a'] ++;
            
            if(j-i+1 < k)
                j++;
            
            else if(j-i+1 == k)
            {
                if(hash == pattern)
                {
                   res.push_back(i); 
                }
                if(hash[s[i]-'a'] != 0)
                    hash[s[i]-'a']--;
                i++;j++;
                
                
                
            }
        }
        
        
        return res;
        
    }
};