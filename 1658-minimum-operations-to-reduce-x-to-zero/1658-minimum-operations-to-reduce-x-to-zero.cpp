class Solution {
public:
    
    // sum of removed elements = X and we want to remove minimum elemetns hence we can think of it as 
    // K = sum - X , and we need to maximise this remaining subarray 
    
    // now our task is find subaarray whose sum is (sum - X) and its length is maximum ( because we want to remove minimum number of elements , so we will have to maximise remianing element ) .
    
    int minOperations(vector<int>& nums, int x) {
        
     //int i, sum1=0, sum2=0,k=0, n=nums.size(), len=0;
     int len=0,sum1=0,sum2=0;
       int n= nums.size();
        
        for(int i=0;i<n;i++)
        
            sum2 += nums[i];
            //SUM2 = DESIRED SUM 
            sum2 -=x;
            if(sum2 ==0) // sum of array = X i.e remove all the elements 
              return n;
        
		// sum2 is desired sum while sum1 is current sum
        int i=0;
        for(int j=0;j<n;j++)
        {
            sum1+=nums[j];
			cout<<sum1;
            while(i<n && sum1>sum2) // if sum of current subaaray is greater than desired sum
            {   sum1-=nums[i];
                 i++;
            }
				
            if(sum1==sum2)  // if sum of current subarray is equal to desired sum then update length
                len=max(len,j-i+1); // we want subarray  with maximum length 
        }
        if(!len)        // No subarray found with desired sum .
            return -1;
        return n-len;
    }
};