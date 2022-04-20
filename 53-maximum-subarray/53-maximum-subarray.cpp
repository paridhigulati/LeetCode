class Solution {
public:

   //brute 2 for loop 
   int maxSubArray(vector<int>& nums) {

   int currSum = 0;
       int maxSofar= INT_MIN;
       
       for(int i=0;i<nums.size();i++)
       {
           currSum += nums[i];
           maxSofar = max(maxSofar, currSum);
           
       
       if(currSum < 0) 
          currSum = 0;
       }
       return maxSofar;
   }
};
       