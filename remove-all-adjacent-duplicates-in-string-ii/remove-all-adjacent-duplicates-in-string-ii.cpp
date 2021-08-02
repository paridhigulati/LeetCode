class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        int count=0;
        string ans;
        st.push({'*',0});
        for(int i=0;i<s.size();i++)
        {
            
            if(st.top().first==s[i])
            {
            if( ++st.top().second==k)
              
                 st.pop();
            }
            else
                st.push({s[i],1});
        }
        while(!st.empty()){
         ans += string(st.top().second, st.top().first);
        st.pop();}
 reverse(ans.begin(), ans.end());
        return ans;
    
    }
    
};