class Solution {
public:
    int majorityElement(vector<int>& nums) {
  
       //moore voting algo : since the maxElement would be present more than n/2 times throughout the array, therefore there would be at least 2 adjacent occurrence of maxElement in the array.
        
        int count=0, maxi = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(count ==0)
            {
             maxi = nums[i];
            count=1;
            }
            else 
            {
            if(maxi == nums[i])
                count++;
            else
                count--;
        }
        }
        return maxi;
    }
};
