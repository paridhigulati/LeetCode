class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
            int result=0;
        int mask=0;
        set<int>prefix_set;
        for(int i =30;i>=0;i--){
            mask|=1<<i;
            for(auto num:nums){
                prefix_set.insert(num&mask);
            }
            int temp=result | 1<<i;
            for(int prefix:prefix_set){
                if(prefix_set.count(temp^prefix)){
                    result=temp;
                    break;
                
                }
            }
            prefix_set.clear(); // why we are clearing set coz in 1st iteration it will store the 
			//prefixes till 1st bit and for storing the prefixes till 2nd bit, we need to clear 
			//the previous set content and similarly we will move further
        }
        return result;
    }
};   
    