class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
  
        stack<int>st;
        int n= heights.size();
        int maxi = 0, curr;
        for(int i=0;i<=n;i++)
        {

            if(i==n)
            {
                curr = 0;
            }
            else
            {
                curr = heights[i];
            }
            
            while(!st.empty() and  curr < heights[st.top()])
            {
                int top = st.top();
                st.pop();
                
                int width = st.empty()?i: i-st.top()-1;
                int area = heights[top] * width;
                maxi = max(maxi, area);
            }
            st.push(i);
        }
        return maxi;
        
    }
};



        