class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        int res = 0;
        for(int i=0;i<32;i++)
        {
        int lsb = n & 1;
        int revLsb = lsb << (31-i) ;
        res = res | revLsb;
            n = n>>1;
        }
        return res;
         
        
    }
};