class Solution {
public:
      //BRUTE ->  10 lettter window, slide it across the pattern and check if its already seen
       // in this case each letter is being checked 10 times except a few so we can say that if m = length of string and n = length of window t.c = O(m*n)
        
/*1. take a substring of length 10 and push in map with its count.
2. take next substring of length of 10 but it contain 11th latter and doesnt contain 1st latter
3. when all substring push in map with count than cheak the count
4. if count>1 it mean it comes more than one time
5. push in ans
*/
 vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string ,int>mp;      //for track all the count 
    vector<string>ans;                             //for ans
    for(int i=0;i+9<s.length();i++)
    {
        string temp=s.substr(i,10);    // s.substr(i,10) means it take a substring of length 10 starting 
        mp[temp]++;                           //  from i th index. 
    }
    for(auto val:mp)                  // traverse in map
    {
        if(val.second>1) ans.push_back(val.first);      //if vaal.second>1 consider in ans
    }
    return ans;
 
    }
};