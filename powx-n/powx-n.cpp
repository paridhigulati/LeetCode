

//if n is 0 return 1

//if n is even call recursive function for n = n/2

//and if n is odd call function x*x^n-1

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        
        double y = myPow(x,n/2);
        if(n%2==0){
            
            return y*y;
            
        }
        else{
            return n < 0 ? 1/x*y*y : x*y*y; 
        }
    }
};