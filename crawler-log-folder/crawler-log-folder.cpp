class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>st;
        int count=0;
        for(int i=0;i<logs.size();i++)
        {
            if (logs[i] == "../")
            {
                if(!st.empty())
                    st.pop();
                count++;
            }
            else if(logs[i]=="./")
            {
                continue;
            }
           
            else{
                st.push(logs[i]);
            }
                
        }
        return st.size();
    }
};
 