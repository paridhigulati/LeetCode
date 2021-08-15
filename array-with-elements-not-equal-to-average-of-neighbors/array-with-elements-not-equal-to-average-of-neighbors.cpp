class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        
        vector<int> result(n);
        int j = 0;
        int i = 0;
        for(; i < n && j < n; i++, j += 2) //alternately fill so that you leave one space in between for large number
            result[j] = nums[i];
        
        
        j = 1;
        for(; i < n && j < n; i++, j += 2) //filter the large number in spaces between that we left above
            result[j] = nums[i];
        
        return result;
    }
};
