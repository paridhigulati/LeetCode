class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int>freq(256,0); // stores all 256 ascii char

        
        string ans = "";
        
        if(s.size() < t.size() || s.size()==0 || t.size()==0)
            return "";
        
        for(int i=0;i<t.size();i++)
        {
            freq[t[i]]++;
        }
        int start = 0, end = 0, windowStart = 0;
        
        int minLen = INT_MAX; 
        int count=0;
        while(end < s.size())
        {
            //to include the given element in window 
            if(freq[s[end]] > 0 ) count++;
            
        // to slide the window
            freq[s[end]]--;
            
            while(count == (int)t.size())
            {
                if(minLen > end-start + 1)
                {
                minLen = end-start + 1;
                windowStart = start;
                }
                
                freq[s[start]]++; //  restore freq, since we are sliding 
                 
                if(freq[s[start]] > 0 ) // we are shrinking the window and if freq > 0then we are sliding past the character which is present in t so our condition (count == t.size) is now invalid hence count--
                    count--;
             
                start++;
            }
            
            end++;
        }
        if(minLen == INT_MAX) return "";

          return   s.substr(windowStart, minLen);
        
    }
};
  
 



 