class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //brute -> set
       // set<int>s;      
       //  for(int i=0;i<nums.size();i++)        {
       //      s.insert(nums[i]);        }
       //  int j=0;
       //  for(auto i : s)
       //  {  nums[j] = i; //reaaranging in the nums too
       //      j++;        
       //  }
       //  return s.size();
        
        
        // 2POINTER
        
        int i=0;
        for(int j=1;j<nums.size();j++)
        {
            if(nums[i] != nums[j])
            {
                i++; 
                nums[i] = nums[j];
            }
        }
        return i+1;
        
        }
    };