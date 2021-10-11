class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // agar pair nhi mila to vo invalid aur agar end mai stack empty h lekin ) bacha h to vo bhi invalid 

        int cnt = 0;
        // starting from left to right 
        // check if string is valid or not
        // if not valid replace * with string
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') cnt++;
            else if(s[i] == ')') {
                cnt--;
                if(cnt < 0) {
                    s[i] = '*';
                    cnt = 0; // very imp to reset count after *
                }
            }
        }
        
        cnt =  0; // reseting count to 0 after left to right 
        
        // starting from right to left
        for(int i=s.size()-1; i>=0; i--) {
            if(s[i] == ')') cnt++;
            else if(s[i] == '(') {
                cnt--;
                if(cnt < 0) {
                    s[i] = '*';
                    cnt = 0; // dont forget to reset here also
                }
            }
        }
        string ans = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] != '*') ans += s[i];
        }
        return ans;
    }
};

/*
    NOTE -> WE NEED TO RESET COUNT 3 TIMES 
    1. left to right : closing bracket -> count-- -> s[i] = * --> count = 0
    2. before starting right to left traversal count = 0
    3. right to left. for opening bracket
    */