class Solution {
public:
    //  power of 2 will contains only 1 set bit 
    bool isPowerOfTwo(int n) {

        if(n<=0) return false;
        return !(n&(n-1)); 
        
    }
};
        
        
        
        
        /*    int count =0;
        while(n>0)
        {
        n = n&(n-1);
        count++;
        }
        if(count==1)
          return true;
        else
            return false;
    }
};
*/