class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
       stack<int>s;
        int j=0;
        int n = pushed.size();
        for(int i=0;i<n;i++){
            s.push(pushed[i]);
        while(!s.empty() and s.top() == popped[j]){
             s.pop();
             j++;
        }
        }
        return s.empty();
    }
};