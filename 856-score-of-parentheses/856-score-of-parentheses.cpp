class Solution {
public:
    int scoreOfParentheses(string s) {
        
      
        
        stack<int>st;
        
        for(char c : s) {
            // opening bracket
            if(c == '(') { 
             st.push(0);
            }
            else {
                int cnt = 0;
                // find the total sum
                while(st.top() != 0) {
                    cnt += st.top();
                    st.pop(); 
                }
                // remove score for the opening brace of current )
                st.pop();
                // assign score based on whether the current 
                // closing brace has enclosed brace 
                if(cnt == 0)
                cnt =1;
                else
                    cnt = 2*cnt;
                st.push(cnt);
            }
        }
        int score =0;
        // final score is sum of all remaining brace scores
        while(!st.empty()) {
            score += st.top();
            st.pop();
        }
        return score;
    }
};