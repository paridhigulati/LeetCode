class Solution {
    int target;
    vector<int> partition;
public:
    bool backtrack(int idx, int k, vector<int>& nums){
        // BASE CASE - all elements have been traversed
        if(idx == nums.size()){
            for(auto i:partition)
                if(i != target) //all partitions sould have reached TARGET value
                    return false;
            return true;
        }
        
        //RECURSIVE CASE
        //TRY placing CURRENT ELEMENT in each partition one by one
        for(auto &i:partition){
            if(i + nums[idx] <= target){
                // 1. ADD in current partition
                // 2. CALL for NEXT ELEMENT
                // 3. REMOVE from current partition
                i += nums[idx]; 
                if(backtrack(idx+1, k, nums))
                    return true;
                i -= nums[idx]; //backtracking
                
            }
            
            if(i == 0) //CURRENT ELEMENT is larger than TARGET
                break;
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        partition.resize(k, 0);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(k==0 or nums.size()<k or sum%k)
            return false;
        
        target  = sum/k;
        //sort(nums.rbegin(),nums.rend()); // LARGER ELEMENTS will be placed EARLIER THAN smaller ones
        return backtrack(0, k, nums);
    }
};