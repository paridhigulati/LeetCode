class Solution {
public:
    void sortColors(vector<int>& nums) {
        
          int i=0, // j to i-1 // 1s area
             j=0; // 0 to j-1 0s area
        int k = nums.size()-1; //k+1 to end 2s area
        // i++ when 1 j++ when 0 k-- when 2 
        
        // i to k is unknown
        while(i<=k)
        {
            if(nums[i] == 2)
            {
                swap(nums[i], nums[k]);
                 k--;
              
            }
           else if(nums[i]==1)
            {
                i++;
            }
            else
            {
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }
    }  
    };
  