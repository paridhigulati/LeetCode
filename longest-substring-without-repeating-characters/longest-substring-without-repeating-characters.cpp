class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
        // BRUTE -> generate all the substring (kadane) 0(n^2) 
        
        // better left, right =0  pointers and a set , right++ if not repeating char ,, on getting repeating char , len = right- left and remove from set and left++  TC O(2n) and O(256) sc
       
        set<char> st;
        int maxSize=0, i=0, j=0, n=s.size();
        while(j<n){
            if(st.count(s[j])==0){
                st.insert(s[j]);
                maxSize = max(maxSize, j-i+1);
                j++;
            }
            else{
                st.erase(s[i]);
                i++;
            }
        }
        return maxSize;
    }
};
       //BEST 
      /*  vector<int> mp(256, -1);
        int right =0, left = 0;
        int  n = s.size();
        int len=0;
       
        while(right < n)
        {
            if(mp[s[right]]!=-1)  left = max(mp[s[right]]+1 , left);
                mp[s[right]]=right;
                len = max(len, right-left+1);
                right++;
        }
        return len;
    }
};*/