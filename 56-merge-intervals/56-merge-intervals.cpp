class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // optimal -> O(nlogn) 
        // sort by start time
       
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
     
        vector<int>temp = intervals[0]; 
        for(auto it : intervals )
        {
            if(it[0] <= temp[1]) // comparing start time 2 and end time 1 
            temp[1] = max(temp[1], it[1]);
            else 
            {
                ans.push_back(temp);
                temp = it;
            }
        }
        ans.push_back(temp);
        return ans;
        
   
    
    }
};