class Solution {
public:
    int majorityElement(vector<int>& nums) {
    /*BRUTE
        map<int,int>mp;
        int n = (nums.size())/2;
        for(int i=0;i< nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto x : mp)
        {
            if(x.second > n)
               return x.first;
        }
        return -1;
    }
};*/
        
        //MOORE VOTING 
        
        int count = 0, elem =0;
        for(auto i : nums)
        {
            if(count==0)
            {
                elem = i;
            }
             if(elem == i)
            {
                count++;
            }
            else{
                count--;
            }
        }
        return elem;
    }
};