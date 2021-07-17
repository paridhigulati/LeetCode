class Solution {
public:
    int hammingWeight(uint32_t n) {
          int count=0;
   while(n>0)
   {
     
     n =  n&(n-1);
       count++;
   }
        return count;
      // return __builtin_popcount(n); //counts no. of set bits 
    }
};


// to check if ith bit is set or not 
//if(nums & (1<<i) != 0 ) 