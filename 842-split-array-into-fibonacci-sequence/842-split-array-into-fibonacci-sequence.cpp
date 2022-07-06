class Solution {
public:
    
        
          bool helper(string& str, int i, int n, vector<int>& ans)
    {
        // this is the base condition, if we reach the end of the str and ans.size() >= 3 then return true.
        
        if(i == n && ans.size() >= 3)
        {
            return true;
        }
        
        // lets we have "1101111" then first we partion into ("1", "101111") or ("110", "1111").. in this way we partition at every index of str
        
        long long num = 0;
        
        for(int j = i; j < n; j++)
        {
            // calculate num
            
            num = num * 10 + str[j] - '0';
            
            // if num > max. value of integer then this can't be included in our ans
            
            if(num > INT_MAX)
                return false;
            
            // if leading digit is zero then this voilets the given condition of question
            
            if(str[i] == '0' && j > i)
                return false;
            
            // if no. of elements in ans array is less than 2, then we just simply insert into ans array 
            
            // if no. of elements in ans array is greater than 2, then we check if the last two number sum up to num, then we insert it into ans array
            
            if((ans.size() < 2) || (((long long) ans.back() + (long long) ans[ans.size() - 2]) == num))
            {
                ans.push_back(num);
                
                if(helper(str, j + 1, n, ans))
                    return true;
                
                // if the added num doesn't lead to ans then we backtrack
                
                ans.pop_back();
            }
        }
        
        return false;
    }
    
    vector<int> splitIntoFibonacci(string str) {
        
        int n = str.size();
        
        // ans store the final ans 
        
        vector<int> ans;
        
        // call the helper function
        
        helper(str, 0, n, ans);
        
        return ans;
    }
};
    