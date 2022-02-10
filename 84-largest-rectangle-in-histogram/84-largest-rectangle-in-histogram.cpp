class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
     
        
        // har index ke liye nearest smaller left aur nearest smaller right nikalo
      // udhar tak hi expand ho skta h 
        
        
//         int n = heights.size() , max_area = INT_MIN , i = 0 ; 
//         stack<int> s ;
//         while(i < n) {
//             if(s.empty() || heights[s.top()] <= heights[i]) {
//                 s.push(i) ; 
//                 i++ ; 
//             } else {
//                 int prev_top = s.top() ; 
//                 s.pop() ; 
//                 max_area = max(max_area , heights[prev_top] * (s.empty() ? i : i - s.top() - 1)) ;
//             }
//         }
//         while(!s.empty()) {
//             int prev_top = s.top() ; 
//             s.pop() ; 
//             max_area = max(max_area , heights[prev_top] * (s.empty() ? i : i - s.top() - 1)) ;
//         }  
//         return max_area ;
//     }
// };
        
//         // area[i] = a[i] * width[i]   ---> width[i] = nsr - nsl-1
      
          int n = heights.size();
        
        // NSL
        vector<int> left;
        stack<pair<int, int>> st;
        int l = -1;
    
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[i] <= st.top().first)
                st.pop();
                
            if (st.empty())
                left.push_back(l);
            else
                left.push_back(st.top().second);
                
            st.push({heights[i],i});
        }
        
        // NSR
        st = {};
        
        vector<int> right;
        int r = n;
        
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[i] <= st.top().first)
                st.pop();
                
            if (st.empty())
                right.push_back(r);
            else
                right.push_back(st.top().second);
                
            st.push({heights[i],i});
        }
        
        reverse(right.begin(), right.end());
        
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1;
            int area = width * heights[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};