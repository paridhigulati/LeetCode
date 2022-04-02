class Solution {
public:
    int countOdds(int low, int high) {
       
        int n = (high-low)/2;
        
        //If the range (high - low + 1) is even, the number of even and odd numbers in this range will be the same.
        
        if(low%2  != 0 || high%2 !=0)
            return n+1;
        
        return n;
    }
    
};