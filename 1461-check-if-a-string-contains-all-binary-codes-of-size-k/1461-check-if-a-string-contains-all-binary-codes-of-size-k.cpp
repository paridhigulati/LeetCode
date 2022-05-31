class Solution {
public:
    bool hasAllCodes(string s, int k) {
       //O(N*K)
//         unordered_set<string>st;
//          if(s.size()<k) return false;
//         for(int i=0;i<s.size()-k+1;i++)
        

//             st.insert(s.substr(i, k));
        
        

//         return st.size()==pow(2, k);
//         }
//     };
        
        //OPTIMISED : O(N) -- ROLLING HASH 
        
        // new hash  = ( old hash << 1 ) & (all ones) | last digit 
        int n = s.size();
        int need = 1 << k; //100
        int allOne = need-1, hashVal = 0;
        vector<bool>flag(1<<k, false);
        for(int i=0;i<s.size();i++)
        {
            hashVal = (hashVal <<  1) & (allOne) | (s[i]-'0');
            
            if(i>=k-1 and !flag[hashVal])
            {
                flag[hashVal]= true;
                 need--;
                if(need == 0)
                    return true;
            }
        }
        return false;
    }
};
        