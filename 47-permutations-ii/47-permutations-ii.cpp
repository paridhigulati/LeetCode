class Solution {
public:
   vector<vector<int>>res;
	vector<bool> vis;
        
        void solve(vector<int>& ans, vector<int>& nums)
    {
            if(ans.size() == nums.size())
            {
                 res.push_back(ans);
                return;
            }
            
        
        for(int i=0;i<nums.size();i++)
        {
            if(vis[i]) continue;
            
            if(i and !vis[i-1] and nums[i] == nums[i-1]) continue;
            
            vis[i] = true;
            ans.push_back(nums[i]);
            solve(ans, nums);
             ans.pop_back();
            vis[i] = false;
        }
        
        
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
          
       vis.resize(nums.size(), false);
        sort(nums.begin(), nums.end());
        vector<int>ans;
        solve(ans, nums);
        return res;
    }
};






	
	
		// for (int i = 0; i < nums.size();++i){//because it is a problem about permutation, we have to iterate from 0.
		// 	if(_visited[i])//1st step to remove duplicates
// 		// 		continue;
// 			if(i && !_visited[i-1] && nums[i]==nums[i-1])//2nd step to remove duplicates
// 				continue;
// 			_visited[i] = true;
// 			cur.push_back(nums[i]);
// 			DFS(nums, cur);
// 			cur.pop_back();
// 			_visited[i] = false;
// 		}
// 	}

   
		// _visited.resize(nums.size(), false);
		// vector<int> cur;
		// DFS(nums, cur);
		// return _res;
