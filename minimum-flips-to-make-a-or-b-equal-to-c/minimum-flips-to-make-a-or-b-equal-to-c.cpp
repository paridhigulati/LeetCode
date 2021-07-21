class Solution {
public:
    int minFlips(int a, int b, int c) {
     
        int count=0;
        int t = 31;
        while(t--)
        {
            int aBit = a&1;
            int bBit = b&1;
            int cBit = c&1;
             
           count += cBit==0? aBit + bBit: 0;
            count +=  cBit==1 && aBit == 0 && bBit ==0? 1:0;
            
            a = a>>1;
            b= b>>1;
            c=c>>1;
        }
        return count;
    }
};



/* C = 0 
A = 1, B = 1 => FLIP COUNT = 2 
    IF C= 1
    A = 0 B =0 => FLIP COUNT = 1 */