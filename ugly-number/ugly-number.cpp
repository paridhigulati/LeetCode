class Solution {
public:

bool isUgly(int num) {
        if(num==0)return false;//<-----0 is neither divisble by 2,3 nor 5
        while(num%2==0)num/=2;
        while(num%3==0)num/=3;
        while(num%5==0)num/=5;
        return num==1;
    }
    
};