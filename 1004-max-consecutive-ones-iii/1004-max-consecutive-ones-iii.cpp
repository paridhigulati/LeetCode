class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int count = 0, ans = -1;
        int window=-1, i=0, j=0;
        
       for (int j= 0; j < nums.size(); j++) {
           
            if (!nums[j])
                count++;
            
            
            while (count > k) {
                if (nums[i]==0) count--;
                i++;
            } 
            
            ans = max(ans, j - i + 1);
        }
        
        return ans;
    }
};