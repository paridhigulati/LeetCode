class Solution {
public:
    vector<int> countBits(int n) {
        // 1.recursive : observation---> even : x/2 odd : x/2 + 1 
        
        vector<int>ans(n+1);
        for(int i=0;i<=n;i++)
        {
            ans[i] = rec(i);
        }
        return ans;
        
    }
     int rec(int num)
    {
        if(num==0) return 0;
         if(num==1) return 1;
         
         if(num%2==0) return rec(num/2);
         else
             return rec(num/2)+1;
    }
};