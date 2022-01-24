class Solution {
public:
    bool detectCapitalUse(string word) {
     bool flag = false;
     int n = word.size();
        int cnt=0,count=0;
        for(int i =0;i<word.size();i++)
        {
            if(isupper(word[i]))
                cnt++;
            else if(islower(word[i]))
                count++;
        }
        if(isupper(word[0]) and count==n-1)
            return true;
        else if(cnt ==n)
            return true;
        else if(count == n)
            return true;
        else
            return false;
        
            

        
        
    }
};