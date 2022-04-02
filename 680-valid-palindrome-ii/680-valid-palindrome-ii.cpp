class Solution {
public:
    bool validPalindrome(string s) {
     // follow up -> delete n chars        
        int i=0, j=s.size()-1;
        
        return Palin(s, i,j,0);
    }
    bool Palin(string &s, int i, int j, int count)
    {
        if(count > 1) return false;
        
       
        while(i < j)
        {
            
          
             if (s[i] != s[j])
            {
                 return Palin(s,i+1,j,count+1) || Palin(s, i, j-1, count+1);
            }
            else
            {
                  i++;
                  j--;
                
            } 
        }
        
            return true;
        
   
    }
};