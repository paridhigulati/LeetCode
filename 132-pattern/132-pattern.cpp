class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //approach from right end num[k] < num[j]  gives single pass 
    
        /* brute force O(n^3)
        if (nums.size() < 3)
            return false;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    int one = nums[i];
                    int two = nums[j];
                    int three = nums[k];
                    if (one < three && three < two)
                        return true;
                }
            }
        }
        return false;
    } 
    }; 
    
    //NLOGN -->using lower bound */

        int size = nums.size();
        if (size < 3) {
            return false;
        }
        // Find the biggest element smaller than current (32 pattern) in O(N^2) time
        vector<int> nextGreatestSmaller(size, INT_MIN);
        set<int> s;
        set<int>::iterator it;
        for (int i = size - 1; i >= 0; i--) {
            s.insert(nums[i]);
            it = s.lower_bound(nums[i]);
            if (it != s.begin()) {
                it--;
                nextGreatestSmaller[i] = *it;
            }
        }
        // Find if there exists any 32 pattern on my right
        int minSoFar = nums[0];
        for (int i = 0; i < size - 2; i++) {
            minSoFar = min(minSoFar, nums[i]);
            if (minSoFar < nextGreatestSmaller[i + 1]) {
                return true;
            }
        }
        return false;
    }
};
        