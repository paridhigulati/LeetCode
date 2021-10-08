class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi = values[0] + 0;
        int ans = -1;
        for(int i=1;i<values.size();i++)
        {
            ans = max(maxi + values[i]-i, ans);
            // (val[i] + i ) + (val[j] - j), maxi here is val[i]+i and values[i]-i is the j bracket , we need to maximise both
            maxi = max(maxi, values[i]+i);
         }
        return ans;
    }
};