class Solution {
public:
  
  //MCM +memo taking every kth balloon bursting in the last;
  
  
  int memo[501][501];
  int solve(vector<int> &nums,int i ,int j){
    if(i>j)return 0;
    if(memo[i][j]!=-1)return memo[i][j];
    
    int max_score=INT_MIN;
    for(int k=i;k<=j;k++){
      int curr_score=nums[i-1]*nums[k]*nums[j+1];
      int temp_score=curr_score+solve(nums,i,k-1)+solve(nums,k+1,j);
      if(temp_score>max_score)max_score=temp_score;
    }
    return memo[i][j]=max_score;
  }
    int maxCoins(vector<int>& nums) {
      memset(memo,-1,sizeof(memo));
      //-1 th position pe && nth pos pe 1 score milega (by example)
      nums.insert(nums.begin(),1);
      nums.push_back(1);
      
      return solve(nums,1,nums.size()-2);
    }
};