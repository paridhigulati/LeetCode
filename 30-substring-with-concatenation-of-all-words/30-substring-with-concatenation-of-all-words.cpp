class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& a) {
     
        
        // 1. since words are of same length, we will start iterating till the wordlen and check              if it exist 
        
        //2.  stopping point here will be once number of words are reached  
        
        //3. edge cases : if s.size() < concat word length  reset if word not present and finally return empty  vector 
        
        //clarifying ques : if duplicate words present 
        
           int wordLen = a[0].size(), windowSize = wordLen * a.size(); 
        vector<int> res;
        if(windowSize > s.size()) return res;
        unordered_map<string, int> original;        
        for(auto &g:a) original[g]++;
		
        //The task of this for loop is to move the window, 1 index at a time.
        for(int i=0; i<=s.size()-windowSize; i++){
            unordered_map<string, int> m;
            
            //The task of this for loop is to check whether all words of vector a are present in window are not.
            for(int windowIndex=i; windowIndex < i+windowSize; windowIndex+=wordLen){
                string curWord = s.substr(windowIndex, wordLen);
				
                //If current word of window doesn't exist in map -> break. Break from 2nd for loop, i.e. window will now move further to next index due to first for loop.
                if(original.find(curWord) == original.end()) break;
                
                m[curWord]++;
                
                //This for loop saves extra iterations if window contains extra duplicates than required
                if(m[curWord] > original[curWord]) break;
                
            }
            
            //Now after exiting window check whether both the maps are identical, if they are we have a result.
            if(m == original) res.push_back(i);
            
        }
        return res;
    }
};