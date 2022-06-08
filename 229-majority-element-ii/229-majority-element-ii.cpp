class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
 /*brute O(nlogn) tc for MAP / frequency array/ unordered map -> O(n)
 // sc o(n)
       map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto i: mp)
        {
            if(i.second > nums.size()/3)
                ans.push_back(i.first);
        }
        return ans;
    }
};
*/
        //optimal -> moore voting O(n) tc O(1) sc
        // observation :  there cannot exist more than 2 majority elem
       
       int cx=0,cy=0,x=0, y=0;
        int count = nums.size()/3;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == x)
                cx++;
            else if(nums[i] == y )
                cy++;
            
            else if(cx == 0)
            {
                x = nums[i];
                cx = 1;
            }
            else if(cy == 0)
            {
                y = nums[i];
                cy=1;
            }
            else
            {
                cx--;
                cy--;
            }
        }
        cx=0, cy=0;
        for(int i=0;i<nums.size();i++)
        {
            if(x == nums[i]) cx++;
            else if(y == nums[i]) cy++;
        }
        if(cx > count)
        ans.push_back(x);
        if(cy > count)
        ans.push_back(y);
        return ans;
        //return {x,y};
    }
};