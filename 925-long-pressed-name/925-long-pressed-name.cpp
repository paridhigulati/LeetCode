class Solution {
public:
    bool isLongPressedName(string name, string typed) {
     // 2 pointers 
        
       // if(name.size() > typed.size()) return false;
        
        int i=0,j=0;
        while(i < name.size() and j<typed.size())
        {
            if(name[i] == typed[j])
            {
                i++; j++;
            }
            else
            {
                if(i-1 >= 0 and typed[j] == name[i-1])
                {
                    // ab aab
                    j++;
                }
                else{
                    return false;
                }
                
            }
        }
        while( j < typed.size()) //invalid j "alex"  "aaleexa"
        {
        if(name[i-1] != typed[j])
        return false;
            j++;
        }
        //invalid i "alexd"  "ale"
        return (i<name.size())?  false : true;
        
       
    }
};
// edge case -> a b => i-1 will give runtime error
// name size < typed size => 
// invalid i 