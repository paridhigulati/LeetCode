class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
//         vector<int>res; // o(n)
//         unordered_map<int,int>mp;
//         for(int i=0;i<nums.size();i++)
//         {
//             int tar = target - nums[i];
//             if(mp.find(tar) != mp.end())
//             {
//                 res.push_back(i);
//                 res.push_back(mp[tar]);
//             }
//             else
//             {
//                 mp[nums[i]]=i;
//             }
//         }
//         return res;
//     }
// };
        
      //  2pointers, ==> sorted  nlogn 
     vector<pair<int,int>>v;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],i});
            
        }
        sort(v.begin(), v.end());
        int l = 0, r = nums.size()-1;
        while(l < r)
        {
            int sum  = v[l].first + v[r].first ;
            if(sum == target)
            {
                
             return { v[l].second, v[r].second};
            }
                else if(sum > target)
                    r--;
            else
                l++;
        }
     return {};
    }
};
             