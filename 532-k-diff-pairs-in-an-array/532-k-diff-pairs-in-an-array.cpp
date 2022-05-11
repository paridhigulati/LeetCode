class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
       unordered_map<int,int>mp;
        
        int n =  nums.size();  
        int count =0 ;
        
        for(int i =0;i<nums.size();i++)
        {
          mp[nums[i]]++;
         }
      
        
         for(auto it : mp)
         {
            
             if(k==0)
             {
                 if(it.second > 1)
                     count++;
             }
            else if(mp.count(it.first + k))
                count++;
         
        }
        
        
        
        return count;
    }
};