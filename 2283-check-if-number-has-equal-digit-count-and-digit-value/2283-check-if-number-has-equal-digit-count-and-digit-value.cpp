class Solution {
public:
    bool digitCount(string nums) {
       
     unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]-'0']++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(mp[i] != nums[i]-'0')
                return false;
        }
        return true;
    }
};
  // unordered_map<int,int> mp;
  //       for(auto x:num) mp[x-'0']++;
  //       for(int i=0;i<num.size();i++){
  //           if(num[i]-'0'!=mp[i]) return false;
  //       }
  //       return true;
  //   }