class Solution {
public:
    
 



    
    int search(vector<int>& nums, int target) {
    
        //BRUTE -> LINEAR SEARCH 
        //OPTIMAL -> find pivot and check if target lies btwn it or not
   int low =0, high = nums.size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(target == nums[mid])
            {
                return mid;
            }
            else if(nums[mid] >=  nums[low] )
            {
                //low to mid part is sorted so check if target lies here 
                if(target >= nums[low] and target < nums[mid])
                {
                    high = mid-1;
                }
            
            else {
                low = mid+1;
            }
          }
            else if(nums[mid] < nums[high])
            {
                //mid to high part is sortedd
                if(target > nums[mid] and target <= nums[high])
                {
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            // else
            //     low++;
        }
                return -1;
    }
    
};
    