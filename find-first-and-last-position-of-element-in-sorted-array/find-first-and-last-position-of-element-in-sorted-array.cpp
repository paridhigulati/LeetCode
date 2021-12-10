class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        //brute -> for first occurence start loop from i=0 and for last occurrence start loop from last index 
        //OPTIMAL - o(logn)
        
       //modified binary search -> if we get the target, still we will mark it as potential ans and look more in the right bocz we want the last occurrence so low = mid +1 
        
      int low = 0, high = nums.size()-1;
      int fi = -1 , li=-1;;
        vector<int>ans;
            while(low <= high)
            {
                int mid  = (low+high)/2;
                if(nums[mid] == target)
                {
                      fi = mid; high = mid-1;                    
                }
                 else if(nums[mid] > target)
                 {
                     high = mid-1;
                 }
                else
                    low = mid+1;
                
            }
        ans.push_back(fi);
       low = 0, high = nums.size()-1;

         while(low <= high)
            {
                int mid  = (low+high)/2;
                if(nums[mid] == target)
                {
                      li = mid; low = mid+1;                    
                }
                 else if(nums[mid] > target)
                 {
                     high = mid-1;
                 }
                else
                    low = mid+1;
                
            }
        ans.push_back(li);
        
        return ans;
        }
};