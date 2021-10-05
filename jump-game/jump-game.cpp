class Solution {
public:
         bool canJump(vector<int>& nums)
         {
	if (nums.size() == 1)return true;
	else return Jump(nums, nums.size() - 1, nums.size() - 2);
       }
bool Jump(vector<int>& nums, int target, int curr)
{
	if (curr == 0)
	{
		if (nums[curr] >= target - curr)
			return true;
		else
			return false;
	}

	if (nums[curr] >= target - curr)
	{
		return Jump(nums, curr, curr - 1);
	}
	else
	{
		curr--;
		return Jump(nums, target, curr);
	}
	return false;
}
    
};