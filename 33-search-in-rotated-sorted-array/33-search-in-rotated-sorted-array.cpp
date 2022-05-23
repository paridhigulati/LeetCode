class Solution {
public:
    
 
int findPivot(vector<int>& arr, int n) {

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

       
    int binarySearch(vector<int>& nums, int target, int s, int e)
    {
        int start = s, end = e;
        while(start <=  end)
        {
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
            {
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
    
        //BRUTE -> LINEAR SEARCH 
        //OPTIMAL -> find pivot and check if target lies btwn it or not
        
        
        int n = nums.size();
        
        int pivot = findPivot(nums, n);
        if(nums[pivot] <= target and target <= nums[n-1])
            //bs on second line
            return binarySearch(nums, target, pivot, n-1);
        else
        //bs  on 1st line
            return binarySearch(nums, target, 0, pivot-1);
        
        //return -1;
    }
};
    