class Solution {
public:
    void sortColors(vector<int>& nums) {
        
          int i=0, j=0; 
          int k = nums.size()-1; 
          
        while(i<=k)
        {
            if(nums[i] == 2)
            {
                int tmp  = 2;
                tmp = nums[i];
                nums[i] = nums[k];
                nums[k] = tmp;
           
                 k--;
              
            }
           else if(nums[i]==1)
            {
                i++;
            }
            else
            {
              
                int tmp = 0;
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                i++;
                j++;
            }
        }
    }  
    };
  