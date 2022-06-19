class Solution {
public:
    
    // sum of removed elements = X and we want to remove minimum elemetns hence we can think of it as 
    // K = sum - X , and we need to maximise this remaining subarray 
    
    // now our task is find subaarray whose sum is (sum - X) and its length is maximum ( because we want to remove minimum number of elements , so we will have to maximise remianing element ) .
    
    int minOperations(vector<int>& nums, int x) {
   
        int n = nums.size(),window = INT_MAX, sum=0, op=0;
        int left=0, right = n-1;
        
        while(left < n)
        {
            sum += nums[left];
            op++;
            if(sum == x) //2stopping points for left : when sum achieved or sum exceeds 
            {
                window = op;
                break;
            }
            else if(sum > x)
            {
                break; 
            }
            left++;
        }
        while(right >=0 and left < n)
        {
            if(sum + nums[right] > x)
            {
                if(left >=  right) // agarleft-- krke left -ve hogya to usko last mai le jao
                    break; // aur ab left right se bada hence break 
                
                sum -= nums[left];
                left--;
                 op--;
                
                if(left < 0)
                {
                left = n-1;
                }
            continue;
        }
            sum += nums[right];
            op++;
            if(sum == x)
         window = min(window, op);
            right--;
            
        }
        return window == INT_MAX?-1:window;
    }
};
        