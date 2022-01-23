class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        
        unordered_map<int,int>mp;
        int cnt=INT_MIN;
        
        for(auto rectangle : rectangles)
        {
            mp[min(rectangle[0], rectangle[1])]++;
            cnt = max(cnt, min(rectangle[0], rectangle[1]));
        }
        return mp[cnt];
    }
};

       