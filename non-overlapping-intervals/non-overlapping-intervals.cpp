class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count =0;
        int n = intervals.size();
        int left=0;
        int right = 1;
        
        while(right<n)
        {
            // case 1 non overlapping i.e start of second > = end of first 
            if(intervals[left][1] <= intervals[right][0]){
             left = right;
              right+=1;
            }
            else if(intervals[left][1] <= intervals[right][1]) // case 2 : partial overlap, remove the larger interval
            {
                count+=1;
                right+=1;
            }
            // case 3 : complete overlap
            else {
                count+=1;
                left = right;
                right+=1;
            }
        }
        return count;
    }
};