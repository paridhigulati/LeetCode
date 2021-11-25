class Solution {
public:
    bool isLongPressedName(string name, string typed) {
          
       
        int i =0, j=0; // initialize two pointers to 0
       
        while(i< name.size() && j <typed.size()){ // while loop till the size of name and typed string is greater than i and j respectively
            if(name[i] == typed[j]){ // check if the character at i and j are same if yes than  
            //increment i & j pointer
                i++; j++;
            }else if( i> 0 && name[i-1] == typed[j]){// if the charcters are not same check for the i-1 character & j if they are same than increment j only
                j++;
            }else{//if all the above cases are not satisfied return false 
                return false;
            }
        }
         while(typed.size() > j ){          // alexa alexad
              if(name.at(i-1) != typed.at(j))
                  return false;
               j++;
        }
        return i< name.size() ? false : true;
    }
};