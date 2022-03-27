class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
//         vector<int>res;
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
        
      //  2pointers, ==> sorted 
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++)
            v.push_back({nums[i], i});
        
        sort(v.begin(), v.end());
        int left =0, right = nums.size()-1;
        while(left < right)
        {
            int sum = v[left].first + v[right].first;
            
            if(sum == target)
               return { v[left].second, v[right].second};
            else if(sum > target)
                right--;
            else
                left++;
        }
        return {};
    }
};
             