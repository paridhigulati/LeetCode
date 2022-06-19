class Solution {

public:
    long long countSubarrays(vector<int>& nums, long long k) {
    long long int currsum=0;
    int i=0,j=0;
    long long int ans=0;
    int windowsize=0;
    while(j<nums.size()){
       currsum+=nums[j];
       j++;
       windowsize++;
       while(currsum*windowsize>=k){
           currsum-=nums[i];
           i++;    //keep on decreasing elements from the start of our window till the required condition is reached//
           windowsize--; // maintaing the window size//
       }
      ans+=windowsize;   // for every new entry in the window there are windowsize new possible subarrys//
    }
        return ans;
  }
    };