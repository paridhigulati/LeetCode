class Solution {
public:
  
  // for each character, we count unique characters between its first and last occurence.
      int countPalindromicSubsequence(string s) {
   
        map<char,int >right;
        for (int i=s.size()-1;i>=0;i--)
        {
            if (right[s[i]]==0)
            right[s[i]]=i; 
            
        }
        
        int ans=0;
        
        set<char>s1;
        for (int i=0;i<s.size();i++)
        {
            if (right[s[i]]==i)
            {
                continue; // right most occurence = left most occurence i.e single occurence
            }
            else
            {
                if (s1.find(s[i])!=s1.end())
                {
                    continue;// we have kept this element at the corners 
                }
                
                s1.insert(s[i]); // s[i] is at both corners of palindrome 
                
                set<int>s2;
                
                // 26 times
                
                for (int j=i+1;j<=right[s[i]]-1;j++)
                {
                    s2.insert(s[j]); // to find the distint elements in between the left most occcurence and right most occurence
                    
                   
                }
                 ans+=s2.size();
                    cout<<s2.size()<<endl;
                
                
                
                
                
            }
        }
        return ans;
        
        
        
    }
};

// O(26*N)