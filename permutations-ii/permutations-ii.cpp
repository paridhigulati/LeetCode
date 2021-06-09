class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int> &nums,vector<int> temp,vector<int> &vis){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(vis[i]==1 || (i>0 && nums[i-1]==nums[i] && vis[i-1]==-1)){
                continue;
            }
            else{
                vis[i]=1;
                temp.push_back(nums[i]);
                backtrack(nums,temp,vis);
                vis[i]=-1;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> vis(nums.size(),-1);
        sort(nums.begin(),nums.end());
        backtrack(nums,{},vis);
        return ans; 
    }
};