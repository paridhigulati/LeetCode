class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
       
        int ans=0;
        if(n==0) return 0;
        
        for(int i=1; i<=n-2;i++)
        {
            if(arr[i-1] <arr[i] and arr[i]> arr[i+1]) //peak found 
            {
                int j=i;
                 int countPeak = 1;
                while(j>0 and arr[j] > arr[j-1]) // find valley on both sides now 
                {
                    j--, countPeak++;
                }
                int k = i;
                while(k<n-1 and arr[k] > arr[k+1])
                {
                    k++, countPeak++;
                }
                ans = max(ans, countPeak);
            }
          
        }
        return ans;
    }
};