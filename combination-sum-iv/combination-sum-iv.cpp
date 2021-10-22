class Solution {
public:
     
      /*  The above solution will always loop for N times for each curtarget from 1 to target. We could achieve slightly better performance if we sort the array at start and break as soon as nums[i] becomes greater than curTarget in the inner loop. The same optimization can be done for Top-Down approach of Solution - II as well.
*/
int combinationSum4(vector<int>& nums, int target) {
	sort(begin(nums), end(nums));
    vector<uint> dp(target + 1); dp[0] = 1;
	for (int curTarget = 1; curTarget <= target; curTarget++) 
        for (auto& num : nums) 
            if (num <= curTarget)  dp[curTarget] += dp[curTarget - num];
            else break;
    return dp[target];
}
};

    /*Time Complexity : O(N*T). Although the time complexity remains same, the performance would be better in most cases since we wouldn't need to loop N times for every curTarget

Space Complexity : O(T)
    }
};*/