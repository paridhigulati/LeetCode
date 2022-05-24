class Solution {
public:
    int longestValidParentheses(string s) {
     
        // if open, push 
        //close => 1. pop char stack and calculate len if u find (
        
        stack<char>charac;
        stack<int>index; 
        
        index.push(-1);
        int maxi = 0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                charac.push(s[i]);
                index.push(i);
            }
            else if(s[i] == ')')
            {
                if(charac.size()!=0 and charac.top() == '(')
                {
                    index.pop();
                    charac.pop();
                   maxi = max(maxi , i - index.top());
                }
                else
                {
                    index.push(i);
                }
            }
        }
        return maxi;
    }
};