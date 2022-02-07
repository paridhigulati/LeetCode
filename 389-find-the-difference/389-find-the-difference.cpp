class Solution {
public:
    char findTheDifference(string s, string t) {
     
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         for(int i=0;i<t.size();i++)
//         {
//             if(t[i]!=s[i])
//              return t[i];
//         }
//         return '-1';
//     }
// };
        string sum= s+t;int ans=0;
        
        cout<<s+t;
        for(int i=0;i<sum.length();i++){
            ans^=sum[i];
        }
        return ans;
    }
};