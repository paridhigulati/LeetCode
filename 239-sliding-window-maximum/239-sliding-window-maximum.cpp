class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // agar to top se bada h to baki ke hata do element deque se
        // agar to chhhota h to push    INDEX KYUKI DUPLICATE VAL HO SKTI H 
        // har window mai max = dq.front update krte rho 
        
        deque<int>dq;
        int n= nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(dq.front() == (i-k) and !dq.empty()) 
            dq.pop_front(); // agar empty nhi h nd window size exceed
            
            while(!dq.empty() and nums[i] > nums[dq.back()])
            
             dq.pop_back(); // agar top se bada to pop 
             dq.push_back(i);//aur jo bada h usko insert krdo
            
            // agar window k size ki complete to ab max nikalo jo front pr pada h
            if(i >=k-1 )
                ans.push_back(nums[dq.front()]);
            
        }
        return ans;
    }
};
   