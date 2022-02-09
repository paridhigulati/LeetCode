class Solution {
public:

    
    bool pairCheck(char open, char close)
    {
        if(open == '(' and close==')') return true;
       else if(open=='{' and close == '}') return true;
      else  if(open=='[' and close==']') return true;
        return false;
    }
    bool isValid(string s) {
        
        // 3 cases to check  
        //1. closing and opening should match i.e [{]} return false
        // 2. closing = opening (after pop, st should be empty)
        	
        
        stack<char>st;
        for(int i=0;i< s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else if ( s[i]==')' || s[i]=='}' || s[i]==']')
                {
                 if(st.empty() || !pairCheck(st.top(), s[i]) ) // closing > opening or pair mis match
                return  false;
                else
                st.pop();
            }
            
        }
     	return st.empty() ? true:false;

    }
};