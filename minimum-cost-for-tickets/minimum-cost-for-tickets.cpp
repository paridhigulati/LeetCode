class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       
      int ans = solve(days, costs, 0);
        return ans;
    }
    int dp[10001];
    int solve(vector<int>& days , vector<int>& costs, int i)
    {
        if(i>= days.size()) //base case, all days covered
            return 0;
        if(dp[i]>0)
            return dp[i];
         int op1 =  costs[0] + solve(days, costs, i+1);
         int k = i;
        for(; k<days.size();k++)
        {
            if(days[k] >= days[i] + 7)
            {  break;}
        }
        int op2= costs[1] + solve(days, costs, k);
        int l=k;
        for(; l<days.size();l++)
        {
            if(days[l] >= days[i]+30)
            {break;}
        }
        int op3 = costs[2] + solve(days, costs,l);
        
        
        dp[i]=min({op1,op2,op3});
        return dp[i];
       // return min(op1, (min(op2,op3)));
    }
    
    
};
 
 
        
      
    

      
        