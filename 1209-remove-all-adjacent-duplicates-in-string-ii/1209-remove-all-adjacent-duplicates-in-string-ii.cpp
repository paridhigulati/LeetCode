class Solution {
public:
    string removeDuplicates(string s, int k) {
     
        stack<pair<char,int>>st;
        string ans;
        
        for(int i=0;i<s.size();i++)
        {
        
        if(st.size()==0 || st.top().first != s[i])
      {
          st.push(make_pair(s[i], 1));
      }
            else{
                st.top().second ++;
                if(st.top().second==k)
                    st.pop();
            }
          }
        while(st.size() > 0)
        {
            while(st.top().second > 0)
            {
                ans += st.top().first ;
                st.top().second--;
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};