class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
  
     
        int maxi = 0, cnt=0;
        
        for(int i=0;i<arr.size();i++)
        {
            //find the index till the effect will last 
            maxi = max(maxi, arr[i]);
            if(i == maxi)
                cnt++;
        }
        return cnt;
    }
};