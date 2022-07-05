class Solution {
public:
    
    bool isVowel(char ch)
    {
        return (ch=='a' || ch =='e' || ch=='i' || ch=='o' || ch=='u') ;
        
        
    }
     int maxVowels(string s, int k) {
      
         int ans = 0, i=0,j=0, count=0;
         
        
         while(j< s.size())
         {
             if(isVowel(s[j]))
                 count++;
             
             if(j-i+1 < k)
                 j++;
             
             else if(j-i+1 == k)
             {
                 ans = max(ans, count);
                 if(isVowel(s[i]))
                     count--; //release the first char of window if its a vowel to shift the window 
                    i++;
                 j++;
             }
         }
         return ans;
         

    }
};



































