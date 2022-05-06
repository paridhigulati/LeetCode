class Solution {
public:
    string removeDuplicates(string s, int k) {
     
       // optimal
        
        vector<pair<char, int>>st;
        
        for(int i=0;i<s.size();i++)
        {
            if(st.size()==0 || st.back().first != s[i])
            {
                st.push_back({s[i], 1});
            }
            else{
                
                st.back().second++;
                if(st.back(). second == k)
                    st.pop_back();
            }
        }
        string ans;
        while(st.size() !=0)
        {
            ans.append(st.back().second, st.back().first);
            st.pop_back();
        }
       reverse(ans.begin(), ans.end());
        return ans;
    }
};
                
      
           
    