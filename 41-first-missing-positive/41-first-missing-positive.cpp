class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
     
        
//       int i=0, n = nums.size();
//         while( i  < n)
//         {
//              crct = nums[i] - 1;
//             if(nums[i] != i+1 && nums[i]>0 && nums[i]<=n && nums[i] != nums[crct])
//             {
//                 swap(nums[i] , nums[crct]);
//             }
//             else
//             {
//                 i++;
//             }
//         }
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i] != i+1)
//             {
//                 return i+1;
//             }
//         }
            
//         return n+1;
        
    
//     }
// };

   int i = 0, n = nums.size();
        while(i<n){
        
        if(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]){
            swap(nums[i], nums[nums[i] -1]);
        } else{
            i++;
        }}
        for(int index=0; index<n; index++){
            if(nums[index]!=index+1){
                return (index + 1);
            }
        }
        return n+1;
    } 
};