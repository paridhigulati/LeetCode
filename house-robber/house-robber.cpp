
class Solution {
public:
    /*Time  Complexcity  :  O ( 2^N )   Give you TLE
Space Complexcity : O( 1 )
    int solve(vector<int>& nums,int index){
        if(index>=nums.size())return 0;
        return max(nums[index]+solve(nums,index+2),solve(nums,index+1));
    }
    int rob(vector<int>& nums) {
        return solve(nums,0);
    }
}; */
      int solve(vector<int>& nums,int index, vector<int>& memo){
        if(index>=nums.size())return 0;
          if(memo[index]!=-1)
              return memo[index];
        return memo[index] = max(nums[index]+solve(nums,index+2,memo),solve(nums,index+1,memo));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>memo(n+1,-1);
        return solve(nums,0,memo);
    }
};