class Solution {
public:
    bool isLongPressedName(string name, string typed) {
     // 2 pointers 
        
      int i=0,j=0;
        
        while(i < name.size() and j < typed.size())
        {
            if(name[i] == typed[j])
            {
                i++;
                j++;
            }
            else
            {
               if (  i-1 >=0 and  typed[j] == name[i-1])
                {
                //a b 
                j++;
            }
            else 
            { 
                return false;
            }
         }
        }
        
        while(j < typed.size())
        {
            if(typed[j] !=name[i-1])
           
                return false;
                j++;
            
            
        }
         if( i < name.size())
         {
             return false;
         }
            
        
        return true;
    }
      
};
// 3 edge case -> a b => i-1 will give runtime error
// invalid j 
// invalid i 