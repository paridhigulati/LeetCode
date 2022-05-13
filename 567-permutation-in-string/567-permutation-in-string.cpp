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
       
        vector<int>freq(26);
        
        for(int i=0;i<s1.size();i++)
        {
            freq[s1[i] -'a']++;
        }
        int window = s1.size();
        
        for(int i=0;i<s2.size();i++)
        {
            freq[s2[i]-'a'] -= 1;
            
            if(i-window >= 0)
            freq[s2[i-window]-'a']++; //sliding 
            //if at any point, entire vec becomes zero, return true 
            
            if(allZero(freq)) 
                return true;
        }
         return false;   
        }
    bool allZero(vector<int>v)
        
    {
        for(int i=0;i<26;i++)
        {
            if(v[i] != 0) return false;
        }
        return true;
    }
    
    };
        