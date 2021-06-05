class Solution {
public:
    /* RECURSIVE Time complexity:O(2^n) TLE
   //Space complexity:O(n)
    int climbStairs(int n) {
        
        if(n==0)
        { return 1; }
        if(n<0){  return 0; }
    int ways = climbStairs(n-1) + climbStairs(n-2);
        return ways;
    }
}; 
  
      
    int mem(int n,vector<int>ans)
    {
        if(n==0)
            return 1;
        if(n<0)
            
        return 0;
        ans[0]=1;
        if(ans[n]!=-1)
            return ans[n];
       
      return  ans[n] = mem(n-1,ans)+mem(n-2,ans);
        
    }
        int climbStairs(int n) 
        {
            vector<int>ans(n+1,-1);
           return mem(n,ans);
        }
         
};*/


    
    int climbStairs(int n) {
	    if(n<1) return 0;
        int a[100];
        a[0]=1;
        a[1]=2;
        for(int i=2;i<n;i++)
            a[i]=a[i-1]+a[i-2];
        return a[n-1];
    }
};