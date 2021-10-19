class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     // brute -> merge 
        int n = nums1.size();
        int m = nums2.size();
        vector<int>ans(n+m);
        int k =0, j=0,i=0;
        int s = n+m;
        while(i<n and j<m)
        {
            if(nums1[i] < nums2[j])
            {
                ans[k] = nums1[i];
                i++,k++;
                
            }
            else
            {
                ans[k] = nums2[j];
                j++,k++;
            }
        }
        while(i<n)
        {
            ans[k] = nums1[i];
            k++, i++;
        }
        
        while(j<m)
        {
            ans[k] = nums2[j];
             k++, j++;
        }
       
        
            if(s%2==0)
            {
                int mid = s/2;
                int m = mid-1;
                return (ans[mid] + ans[m])/2.0 ;
            }
        else 
            return ans[(s)/2]*1.0;
        
    }
};

   
        
    
       