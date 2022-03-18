class Solution {
public:
    string removeDuplicateLetters(string s) {
        
      // 1. 
         vector<int>mp(26,0);
        vector<bool>vis(26,false);
        stack<char>st;
        
        for(int i =0;i<s.size();i++)
        {
            mp[s[i]-'a']=i;
        }
        
        for(int i=0;i<s.size();i++)
        {
            int curr = s[i]-'a';
            if(vis[curr]) continue;
            while(st.size()>0 and st.top() > s[i] and mp[st.top()-'a'] > i)
       
            {
                    
                      vis[st.top()-'a'] = false;
                        st.pop();
                    
            }
                    st.push(s[i]);
                     vis[curr] = true;
                
               
            }
        
        string ans="";
        while(!st.empty())
        {
           ans += st.top();
            st.pop();
        }
          reverse(ans.begin(), ans.end());
        return ans;
       
    }
};