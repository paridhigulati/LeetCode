class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0 ;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                cnt++;
        }
        if(cnt <= 1) return 0;
        
        int window=cnt;
        int tmp= 0;
        
    int maxOne;
        
        for(int i=0;i<window;i++)
        {
            if(nums[i] == 1)
                tmp++;
        }
        maxOne = tmp;
        
        for(int  i = window ; i< n+ window ; i++)
        {
            if(nums[i-window] == 1) tmp--;
                
                if(nums[i%n] == 1 )
                    tmp++;
            maxOne = max(maxOne, tmp);
        }
        return window-maxOne;
            
            
        }
};