class Solution {
public:
    int lengthOfLongestSubstring(string s) { //largest window with all unique char 
   
        if(s.size()==0) return 0;
        int  n = s.size(), i=0;
        int j= 0, ans = INT_MIN;
        unordered_map<int,int>mp;
     
        while(j < n)
        {
            mp[s[j]]++;
        
     
            if(mp.size() == j-i+1)
            {
                ans = max(ans, j-i+1);
            }
            
          else if ( mp.size() < j-i+1)
          {
              while(mp.size() < j-i+1)
              {
                  mp[s[i]]--;
                  
                  if(mp[s[i]] == 0)
                   mp.erase(s[i]);
                  
                  i++;
              }
          }
          
     j++;
        
        }
        return ans;
    }
};