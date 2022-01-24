class Solution {
public:
        
     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) {
                res.push_back(a);
                m.erase(a);
            }
     
        return res;
    }

};
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         int l1=nums1.size(),l2=nums2.size();
//         vector<int> ans;
        
//             int arr[1001]={-1};
//             for(int i=0;i<l1;i++){
//                 arr[nums1[i]]=1;
//             }
//             for(int i=0;i<l2;i++){
//                 //if element is present in array1 push to ans and make it -1 
//                 if(arr[nums2[i]]==1) {
//                     ans.push_back(nums2[i]); 
//                     arr[nums2[i]]=-1;
//                 }
//             }      