class Solution {
public:
/*    // function to split the string 
    vector<string> split_string(string s, char c = ' ') {
    vector<string> ans;
    int start_idx = 0;
    int n = s.size();
    for (int i = 0; i <= n - 1; ++i) {
        if (s[i] == c) {
            ans.push_back(s.substr(start_idx, i - start_idx));
            start_idx = i + 1;
        }
    }
 
    if (start_idx < n) {
        ans.push_back(s.substr(start_idx));
    }
 
    return ans;
}
    
    string simplifyPath(string path)
    {
        
        // split string 
          vector<string> split = split_string(path, '/');
           stack<string>st;
        for(auto x: split)
        {
            if(x ==  "..")
            {
                if(!st.empty())
                    st.pop();
            }
            else if(x != ".")
                st.push(x); //name
        }
      
        
       vector<string>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
  
    reverse(ans.begin(), ans.end());
    int sz = ans.size();
    string ans_s = "/";
    for (int i = 0; i <= sz - 1; ++i) {
        ans_s += ans[i];
        if (i < sz - 1) {
            ans_s = ans_s + "/";
        }
    }
 
    return ans_s;
    }
}; 
    Only need to handle two special cases i.e., "." and "..".
Why I used stack?
Because whenever there is "/../" and ahead of it there is directory "/abc/" or "/", I have to immediately remove directory (/abc/).
e.g. /abc/../ => / */


    string simplifyPath(string path) {
        if(path[path.size()-1]!='/')
            path.push_back('/');
        string dir = "";
        stack<string> st;
        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                if(dir.empty())
                    continue;
                if(dir.compare(".")==0){
                    // ignore
                }    
                else if(dir.compare("..")==0){
                    if(!st.empty())
                        st.pop();            
                }
                else{
                    st.push(dir);
                }
                dir = ""; // remove previous directory
            }
            else
                dir.push_back(path[i]);
        }
        dir = "";
        while(!st.empty()){
            dir =  "/" + st.top() +dir ;
            st.pop();
        }
        return dir.empty() ? "/" : dir;
    }
};