class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int>st;
       // st.push(asteroids[0]);
        for(int i=0;i<asteroids.size();i++)
        {
            if(asteroids[i] >0 || st.empty())
            {
                st.push(asteroids[i]);
            }
            else
            {
            while(st.size()>0 and st.top() >0 and abs(asteroids[i]) > st.top()  )
            {
                st.pop();
            }
                if(st.size()>0 and st.top()== abs(asteroids[i]))
                {
                   st.pop();
                }
            
            else {
                    if(st.empty() || st.top() < 0) {
                        st.push(asteroids[i]);
                    }
        }
            }
       
    }
                vector<int>ans(st.size());

        for(int i=st.size()-1;i>=0;i--)
        {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
            
           