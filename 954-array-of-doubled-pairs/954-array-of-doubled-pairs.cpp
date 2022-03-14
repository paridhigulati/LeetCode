class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        
      unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
         sort(arr.begin(), arr.end(), [](const int& int1, const int& int2) {
        return abs(int1) < abs(int2);
    });
        for(int i : arr)
        {
            if(mp[i]==0)
                continue;
            
            if(mp.find(2*i) != mp.end() and mp[i]>0 and mp[2*i]>0)
              
            { mp[i]--;
                mp[2*i]--;
             }
            else
                return false;
        }
        return true;
    }
};