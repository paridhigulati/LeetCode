class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
      //  int sum=0, total=0;
       
        sort(nums.begin(), nums.end());
          if(nums[0] != 0){
             return 0;
         }
        for(int i=0;i<nums.size()-1;i++)
        {
           if(nums[i+1]-nums[i] != 1)
               return nums[i] + 1;
            
        }
        return nums.size();
    }
};

    //  sort(nums.begin(), nums.end());
    //     if(nums[0] != 0){
    //         return 0; //in the loop, we are checking for higher numbers, since 0 is the lowest, we won't be able to check 0's presence in loop, so checking it here
    //     }
    //     for(int i = 0; i < nums.size()-1; i++){
    //         if(nums[i+1] - nums[i] != 1){
    //             return nums[i]+1;
    //         }
    //     }
    //     return nums.size(); //when the array has all numbers from 0 to n-1, but not n, e.g. in a size 4 array [0,1,2,3], the number remaining is 4
    // }