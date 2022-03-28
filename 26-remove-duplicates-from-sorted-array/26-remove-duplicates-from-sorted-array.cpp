class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //brute -> set
       set<int>s;
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i]) == s.end())
            {
               s.insert(nums[i]);
               nums[j] = nums[i];
                j++;
        }
        }
        return s.size();
        
        
        
        }
    };