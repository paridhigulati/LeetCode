class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> v(n+m);
        int i=0,j=0,c=0;
        while(i<n&&j<m){
            if(nums1[i]<nums2[j]){
                v[c] = nums1[i];
                i++;c++;
            }else{
                v[c] = nums2[j];
                j++;c++;
            }
        }
        while(i<n){
            v[c] = nums1[i];
            i++;c++;
        }
        while(j<m){
            v[c] = nums2[j];
            j++;c++;
        }
        if((m+n)==1){
            return v[0];
        }
        if((m+n)%2==1){
            return v[(m+n)/2]*1.0;
        }else{
            int mid1 = (m+n)/2;
            int mid2 = mid1-1;
            return ((v[mid1]+v[mid2])/2.0);
        }
    }
};