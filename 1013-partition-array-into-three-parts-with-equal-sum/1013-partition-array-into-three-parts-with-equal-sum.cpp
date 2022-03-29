class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
     
        int sum =0, cnt =0;
        
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
        }
        if(sum%3) return false;
        
        else
        {
            int ss  = sum/3;
            int  temp=0;
            
            for(int i=0;i<arr.size();i++)
            {
                temp += arr[i];
                if(temp == ss)
                { temp=0;
                    cnt++;
                }
            }
        }
        if(cnt >=3) return true;
        else
            return false;
    }
};