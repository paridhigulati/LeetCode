class Solution {
public:
    
    bool isVowel( char s)
    {
       return (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u');
    }
    bool halvesAreAlike(string s) {
        int count =0;
        for(int i=0;i<s.size();i++)
        {
          s[i] = tolower(s[i]);
        }
       
        int mid = s.size()/2;
        for(int i=0;i<mid;i++)
        {
           if(isVowel(s[i]))
               count++;
        }
      
        for(int i = mid ;i<s.size();i++)
        {
            if(isVowel(s[i]))
                count--;
        }
        if(count==0)
            return true;
        return false;
    }
};