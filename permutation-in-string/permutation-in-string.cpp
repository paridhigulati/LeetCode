class Solution {
public:
    // brute generating all perm , 2nd method sort both the strings , 3rd map 
    bool checkInclusion(string s1, string s2) {
 //condition for anagram :  should be of same length and same length of unique characters (fired and fried )
        
       /* ques -> all lowercase ? so take hashmap of 26 char 
        Since we are looking for the pmt of s1, we just need to check if can
    find a window the same size as that of s1 which has the same number of chars
    as that of s1. Since it is pmt we are looking for, that can be formed with just
    rearranging the chars in that window.
    TC: O(N), SC: O(1)
*/

        if(s1.size() > s2.size())
            return false;
        vector<int> s1_freq(26, 0), s2_freq(26, 0);
        
        // check if the frequency of s1 is there in s2 with a window size equal to s1
        int i = 0;
        for(; i < s1.size(); i++) {
            // compute the frequency of each char for the first window
            ++s1_freq[s1[i] - 'a'];
            ++s2_freq[s2[i] - 'a'];
        }
        
        if(s1_freq == s2_freq)
            return true;
        // search the remaining windows
        for(; i < s2.size(); i++) {
            // remove the first char of current window and add the current char
            --s2_freq[s2[i - s1.size()] - 'a'];
            ++s2_freq[s2[i] - 'a'];
            if(s1_freq == s2_freq)
                return true;
        }
        return false;
    }
};