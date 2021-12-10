class Solution {
public:
    int candy(vector<int>& ratings) {
       int n = ratings.size();
        vector<int>left(n,1);
        int sum =0;
        for(int i=1;i<n;i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                left[i] = left[i-1]+1;
            }
        }
           for(int j=n-1;j>0;j--)
        {
            if(ratings[j-1] > ratings[j])
            {
                			

            left[j-1]=max(left[j]+1,left[j-1]);

            }
           }
        for(int k=0;k<n;k++)
        {
            sum += left[k];
        }
        return sum;
    }
};