class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        // sum of each row, sort it and store along with its index 
        // return k elements of that vector
        vector<pair<int,int>>v;
        int index  = 0, sum=0;
        for(int i=0;i<mat.size();i++)
        {
            sum=0;
            for(int j=0;j<mat[i].size();j++)
            {
               sum += mat[i][j];
            }
        v.push_back({sum , i});
        }
        sort(v.begin(), v.end());
        vector<int>s;
        for(int i=0;i<v.size();i++)
        {
            s.push_back(v[i].second);
        }
        return vector<int>(s.begin(), s.begin()+k);
        
    }
};