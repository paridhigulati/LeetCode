class Solution {
public:
    int scoreOfParentheses(string s) {
        
        int score = 0;
        int curr_score = 0;
        
        stack<int>st;
        
        for(char &c: s) {
            // opening bracket
            if(c == '(') { 
             st.push(0);
            }
            else {
                int curr_val = 0;
                // find the total sum
                while(st.top() != 0) {
                    curr_val += st.top();
                    st.pop(); 
                }
                // remove score for the opening brace of current )
                st.pop();
                // assign score based on whether the current 
                // closing brace has enclosed brace 
                curr_val = curr_val == 0 ? 1 : 2 * curr_val;
                st.push(curr_val);
            }
        }
        // final score is sum of all remaining brace scores
        while(!st.empty()) {
            score += st.top();
            st.pop();
        }
        return score;
    }
};