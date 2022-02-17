class Solution {
public:
    int calPoints(vector<string>& ops) {
     
        stack<int>st;
        int count =0;
        for(int i=0;i<ops.size();i++)
        {
            
             if(ops[i]=="C")
            {
                st.pop();
            }
            else if(ops[i]=="D")
            {
                int val =st.top();
               st.push( 2*val);
                
               
            }
            else if(ops[i]=="+")
            {
               int v1 =st.top();
                st.pop();
                int v2 = st.top();
                st.pop();
                int sum = v1+v2;
                st.push(v2);
                st.push(v1);
                st.push(sum);
            }
            else{
                st.push(stoi(ops[i]));
            }
        }
            while(!st.empty())
            {
                count += st.top();
                st.pop();
            }
        
        return count;
    }
};
           