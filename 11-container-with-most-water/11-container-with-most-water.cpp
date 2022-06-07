class Solution {
public:
    int maxArea(vector<int>& height) {
       
        int n  = height.size();
        int l=0, r = n-1;
       
        int ans = 0;
        while(l < r)
        {
             int  lh = height[l], rh = height[r];
            int maxh = min(lh, rh) * (r-l);
            
            ans = max(ans, maxh);
            
            if(height[l] < height[r])
                l++;
            else 
                r--;
        }
        return ans;
    }
};