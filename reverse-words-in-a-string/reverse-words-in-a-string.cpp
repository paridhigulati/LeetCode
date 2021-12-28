class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans;
        int i=0;
        while(i<n)
        {
        while(i<n and s[i] == ' ')
         i++;
        if(i>=n) break;
        int j = i+1;
        while(j<n and s[j]!= ' ')
        {
            j++;
        }
      string  word = s.substr(i,j-i); //starting index , length
          if(ans.size()==0) ans = word;
      else  ans = word + " " +ans;
         i = j+1;
        }
        return ans;
    }
         
        
};