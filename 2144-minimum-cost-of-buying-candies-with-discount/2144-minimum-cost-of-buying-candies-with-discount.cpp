class Solution {
public:
    int minimumCost(vector<int>& cost) {
       
        //int n = cost.size();
           // sort(a.begin(), a.end(), greater<int>());

//         sort(cost.begin(), cost.end());
//         //int i=0;
//         int count = 0;
//         int i = n-1;
//         while(i>=0)
//         { 
//             if(i>=0)
//                 count += cost[i];
//              i--;
//               if(i>=0)
//                 count += cost[i];
//              i--;
//             i--;
            
//         //int k=0;
//         }
//         return count;
       
//     }
// };
     
        sort(cost.begin(),cost.end(),greater<int>());
        
        int ans=0,cnt=0;
        for(int i=0;i<cost.size();i++)
        {
            if(cnt==2){
                cnt=0;
                continue;
            }
            cnt++;
            ans+= cost[i];
        }
        
        
        return ans;
    }
};