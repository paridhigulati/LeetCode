class Solution {
public:
    //longest strictly increasing subsequence 

   
     //int maxEnvelopes(vector<vector<int>>& envelopes) {
        
//         int n=envelopes.size();
//         if(n==1) return 1;
//         int res=1;
//         sort(envelopes.begin(),envelopes.end(),cmp);
//         vector<int> dp(n,1);
//         for(int i=1;i<n;i++){
//             for(int j=0;j<i;j++){
//                 if(envelopes[j][0]<envelopes[i][0] && envelopes[j][1]< envelopes[i][1])
//                 {
//                     dp[i]=max(dp[i],dp[j]+1);
//                     res=max(res,dp[i]);
//                 }
//             }
//         }
//         return res;
//     }
// };
    
    
   
   
  static bool compare(vector<int>&a , vector<int>& b)
    {
      return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>&a) {
      sort(a.begin(),a.end(),compare);
      vector<int>dp;
      for(auto i:a)
      {
        auto it=lower_bound(dp.begin(),dp.end(),i[1]);
        if(it==dp.end())
          dp.push_back(i[1]);
        else
          *it=i[1];
      }
      return dp.size();
    }
};