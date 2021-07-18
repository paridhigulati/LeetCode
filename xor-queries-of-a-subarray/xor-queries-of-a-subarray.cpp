class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int pre[arr.size()];
        int n = arr.size();
        pre[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            pre[i] = pre[i-1]^arr[i];
        }
        vector<int>ans;
        for(auto x : queries)
        {
            if(x[0]==0)
          ans.push_back(pre[x[1]]); 
            else
                ans.push_back(pre[x[1]] ^ pre[x[0]-1]);
        }
    
    return ans;
    }
};
