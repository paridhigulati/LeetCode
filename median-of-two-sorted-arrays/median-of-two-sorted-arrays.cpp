class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     /* brute -> merge arrays and find median O(m+n) spaces and O(m+n) time
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
*/
        // OPTIMAL SOLUTION ->BINARY SEARCH 
        if(nums2.size() < nums1.size()) 
            return findMedianSortedArrays(nums2, nums1);
        int n = nums1.size();
        int m = nums2.size();
      
        int low =0, high =n;
        while(low<=high)
        {
            int cut1 = (low+high)>>1;
            int cut2 = (n+m+1)/2 - cut1;
            
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            
            int r1 = cut1 == n ? INT_MAX : nums1[cut1];
            int r2 = cut2 == m? INT_MAX : nums2[cut2];
            
            if(l1 <= r2 and l2 <= r1)
            {
                
                if((n+m)%2)
                   return max(l1,l2);
                else
                   return (max(l1,l2) + min(r1,r2))/2.0;
            }
            else if(l1>r2)
            {
                high = cut1 -1;
            }
            else
                
            {
                low =cut1+1;
            }
            
        }
        return 0;
    }
};
        
        
    
       