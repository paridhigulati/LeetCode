class Solution {
public:
    bool search(vector<int>& arr, int target) {
     // allows duplicate elements
        int low=0, high=arr.size()-1;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
               if(arr[mid] == target)
                return true;
            
            else if(arr[mid] > arr[low]) //left part
            {
                if(target >= arr[low] and target <= arr[mid])
                high = mid-1;
                else
                    low= mid+1;
            }
          
            else if(arr[mid] < arr[low]) //right part
            {
                if(target >= arr[mid] and target <= arr[high] )
                    
                low = mid+1;
                else
                high = mid-1;
               
        }
            else
                low++;
        }
        return false;
    }
};