class Solution {
public:
  static bool cmp(pair<int, int>& a, pair<int, int>& b) { //Sorting in decending order
    return a.second > b.second;
}
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int>ans;
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i ++)
        {
    //       if(mp.find(nums[i]) == mp.end()) {
    //     hash[nums[i]] = 1;
    // }
    // else {
            mp[nums[i]]++;
    
    }
    vector<pair<int,int>> v(mp.begin(),mp.end());
    sort(v.begin(),v.end(),cmp);
    int j = 1;
    for(auto& it : v) {
     if(j <= k)
    ans.push_back(it.first);
    j++;
    }
    return ans;
    }
    };
