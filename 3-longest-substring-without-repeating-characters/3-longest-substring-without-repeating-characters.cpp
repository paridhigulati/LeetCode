class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
        
        int n = s.size();
        int i=0,j=0;
        int window = INT_MIN;
        
        if(s.size() == 0) return 0;
        unordered_map<char,int>mp;
        
        while(j < n)
        {
            mp[s[j]]++;
            
             if(mp.size() == j-i+1)
            {
                window = max(window, j-i+1);
               
            }
            
           else if(mp.size() < j-i+1)
            {
                //duplicates 
                while(mp.size() < j-i+1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
               
            }
       
            j++;
        }
        return window;
    }
};