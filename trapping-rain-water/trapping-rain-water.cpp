class Solution {
public:
    //min(left,right)- arr[i]     BRUTE 
    
int trap(vector<int>& height)
{
    /*
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
}
}; */
    
    // DP -----> O(N) approach
    if(height.empty())
        return 0;
    int n = height.size();
    int ans=0;
    vector<int>leftMax(n),rightMax(n);
    leftMax[0]=height[0];
    rightMax[n-1]=height[n-1];
    for(int i=1;i<n;i++)
    {
        leftMax[i] = max(height[i], leftMax[i-1]);
    }
    for(int i=n-2;i>=0;i--)
    {
        rightMax[i] = max(height[i],rightMax[i+1]);
    }
    for(int i=1;i<n-1;i++)
    {
        ans+=min(leftMax[i], rightMax[i])-height[i];
    }
    return ans;
}
};