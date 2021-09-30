class Solution {
public:
   
           int longestPalindrome(string s) {
        // if the size is 1
        if(s.size()==1)return 1;
        
        // we create a map and store its freq
        unordered_map<char,int> mp;
        
        for(auto x:s)mp[x]++;
        
        int ans=0;
        bool flag = false;
        for(auto x:mp){
            // Now if the char exists even times we can use it all
            if(x.second % 2 == 0) ans+= x.second;
            
            //if we encounter an odd, we will -1 from it and use it
            else{
                ans+= x.second - 1;
                flag = true;
            }
        }
        // if we encountered odd, it means we can use one in the center too
        if(flag)ans++;
       
        return ans;
    }
};













