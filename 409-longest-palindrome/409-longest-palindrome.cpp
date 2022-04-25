class Solution {
public:
    int longestPalindrome(string s) {
       unordered_map<int,int>mp;
        
        int ans= 0;
        
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            if(mp[s[i]] %2 == 0)
            {
                ans += mp[s[i]];
                mp[s[i]]=0;
             }
        }
        
        for(auto i : mp)
        {
            if(i.second == 1)
            {
                ans++;
               break;
            }
        }
        return ans;
    }
};