/*class Solution {
public:
    int reverse(int x) {
        int prev = 0;
        int ans=0;
        while(x)
        {
            int rem = x%10;
            x/=10;
            ans = ans*10 + rem;
            
            //to handle overflow
            if((ans-rem)/10 != prev)
                return 0;
            prev=ans;
        }
        return ans;
    }
};
*/
class Solution {
public:
    int reverse(int x) {
        int y=0;
        while(x){
            if(y>INT_MAX/10 || y<INT_MIN/10){
                return 0;
            }else{
                y=y*10 +x%10;
                x=x/10;
            }
        }
        return y;
    }
};