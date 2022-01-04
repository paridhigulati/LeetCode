class Solution {
public:
    int bitwiseComplement(int n) {
       
        if(n==0) return 1;
        
        int ans=0, p=1;
        while(n)
        {
            int bit = n&1;
            if(bit==0) ans+=p;
            p<<=1;
            n>>=1;
        }
        return ans;
    }
};