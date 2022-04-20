class Solution {
public:
    
    bool check(char open, char close)
    {
        if(open == '(' and close == ')' || open == '{' and close == '}' || open == '[' and close == ']' )
            return true;
        else 
            return false;
    }
    
    bool isValid(string s) {
       
        stack<char>st;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            
            else {
                
                if(!st.empty() and check(st.top(), s[i]))
                    st.pop();
                else
                    return false;
                
            }
        }
            if(st.size()  == 0)
                return true;
            
            return false;
        
    }
};