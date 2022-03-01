class Solution {
public:
    vector<int> countBits(int n) {
        // 1.recursive : observation---> even : x/2 odd : x/2 + 1 
        // memoise it to optimise 
        vector<int>ans(n+1);
         
        for(int i=0;i<=n;i++)
        {
            ans[i] = rec(i, ans);
        }
        return ans;
        
    }
     int rec(int num, vector<int>& ans)
    {
        if(num==0) return 0;
         if(num==1) return 1;
         if(ans[num]!=0) 
          return ans[num];
         if(num%2==0) 
         {
             ans[num] = rec(num/2, ans);
             return rec(num/2, ans);
         }
         else
         {
             ans[num] = 1+rec(num/2, ans);
             return 1 + rec(num/2, ans);
         }
        
    }
};