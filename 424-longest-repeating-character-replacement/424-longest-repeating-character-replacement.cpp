
        
//         Intution : We traverse from each char of the string if the curr char exists on the map we increase the count else we put it in the map .
// Now since we can only replace at most K no of items so if at any time the curr window has more than k replacable items we have to shrink that window .

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int i=0;//->window start
        int j=0;//->window end
        int maxC=0;//->max no of repeating elements 
        int ans=-1;
        unordered_map<char,int> mp;
        while(j<n)
        {
            mp[s[j]]++;
            maxC=max(maxC,mp[s[j]]);
            
            int curr_len=j-i+1;//Curr Len of the window
            if(curr_len-maxC>k) //the curr window has more than k replacable items case
            {
                mp[s[i]]--;
                i++;// shrinking the window
            }
            curr_len=j-i+1;// just in case i is changed e.g ("AABABBA" 1) 
            ans=max(ans,curr_len);
            j++;
        }
        
        return ans;
    }
};
    