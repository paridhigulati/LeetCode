class Solution {
public:
    bool isRobotBounded(string s) {
        pair<int,pair<int,int>> a;
        a={1,{0,0}};
        vector<pair<int,int>>v;
        v.push_back({1,0});
        v.push_back({0,1});
        v.push_back({-1,0});
        v.push_back({0,-1});
        int g=4;
        while(g--)
        for(int i=0;i<s.size();i++){
            if(s[i]=='G'){
                a.second.first+=v[a.first].first;
                a.second.second+=v[a.first].second;
            }
            else if(s[i]=='L'){
                a.first=(a.first+3)%4;
            }
            else if(s[i]=='R'){
                a.first=(a.first+1)%4;
            }
        }
        if(a.second.first==0 && a.second.second==0)return true;
        return false;
    }
};