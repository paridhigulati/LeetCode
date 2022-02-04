class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0;
        int ans=0;
        unordered_map<int,int>mp; // 0th index par -1 sum 
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                nums[i]= -1;
            sum+=nums[i];
        
           if(sum==0)
           {
            ans = i+1;
           }
            if(mp.count(sum)==1) // count returns 1 if key is present in map
            {
                ans = max(ans, i-mp[sum]);
            }
            else
            {
                mp[sum]=i;
            }
        }
            return ans;
        }
    };
            
            
//         unordered_map<int,int>mp;
//         for(int i =0; i<nums.size();i++)
//         {       
//             mp.insert({nums[i], i});
//     }
//         int len =0;
//         for(int i=0;i< nums.size();i++)
//         {
          
//             if(mp[nums[i]] == 0)
//              len = mp[nums[i]].second;       
//         }
//         return len;
//     }
// };