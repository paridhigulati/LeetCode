class Solution {
public:
    //longest strictly increasing subsequence 
    
 bool static cmp(vector<int>& a, vector<int>& b){
       if(a[0] < b[0]) return true;
     
       if(a[0] == b[0])
        return a[1] > b[1];
     return false;
    }

   
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
    
    
   
     int maxEnvelopes(vector<vector<int>>& envelopes) {
    //int maxEnvelopes(vector<pair<int, int>>& envelopes) {
       // if (envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end(),cmp);
        vector<int> dp;
        dp.push_back(envelopes[0][1]);
        int len = 1;
        for (int i = 1; i < envelopes.size(); ++i)
         
        {
            auto itr = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
            if(itr == dp.end())
            {
              dp.push_back(envelopes[i][1]);  
             len++;  
             }
            else
            {
                *itr = envelopes[i][1];
            }
        }
        return len;
    }
};