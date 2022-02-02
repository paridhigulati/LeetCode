class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      
        vector<int> pattern(26,0), string(26,0),res;
        if(s.size() < p.size())
            return res;
        for(int i=0;i<p.size();i++)
        {
            pattern[p[i]-'a']++;
            string[s[i]-'a']++;
        }
        if(pattern== string)
            res.push_back(0);
        for(int i = p.size(); i < s.size(); ++i) 
        {
           string[s[i]-'a']++;           
            // release and acquire
            //aage se ek add kro aur peeche see hatao
            
           // since we added one element to the right, 
            // one element to the left should be discarded. 
            //counter for s[i-p.size()] is decremented
            string[s[i-p.size()]-'a']--;
           if(pattern == string )  // this comparison takes O(26), i.e O(1), since both vectors are of fixed size 26. Total complexity O(n)*O(1) = O(n)
               res.push_back(i-p.size()+1); 
        }
        return res;
           
        
        
        
    }
};