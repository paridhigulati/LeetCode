class Solution {
public:
    bool hasAllCodes(string s, int k) {
       
        unordered_set<string>st;
         if(s.size()<k) return false;
        for(int i=0;i<s.size()-k+1;i++)
        {
            string tmp = (s.substr(i, k));
            st.insert(tmp);
           // cout<<tmp<<endl;
        }
        //cout<<st.size();
        if(st.size() == pow(2,k))
            return true;
        return false;
    }
};
//    for(int i=0;i<s.size()-k+1;i++)
//             st.insert(s.substr(i, k));
        
        
//         //If set's size is equal to 2 power k,
//         //then we have all the possible substrings else we return false
//         return st.size()==pow(2, k);