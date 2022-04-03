class Solution {
public:
    int subtractProductAndSum(int n) {
     
        int prod =1, sum=0;
        
       // string s = to_string(n);
        while(n)
        {
            int s = n%10;
            sum+=s;
            prod*=s;
            n = n/10;
        }
        cout<<sum<<" " <<prod;
        return prod-sum;
    }
};