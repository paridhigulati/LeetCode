class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int>st;
        stack<int>stt;
        string ans;
         string anss;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != '#')
            {
                st.push(s[i]);
            }
            else{
                if(!st.empty()) 
                    st.pop();}
        }
            while(!st.empty()){
            ans.push_back(st.top());
                st.pop();
        }
         for(int i=0;i<t.size();i++)
        {
            if(t[i]!= '#')
            {
                stt.push(t[i]);
            }
            else{ 
                 if(!stt.empty())
                     stt.pop();}
        }
            while(!stt.empty()){
            anss.push_back(stt.top());
                stt.pop();
        }
        return ans==anss;
    }
};