class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
       if(arr[start]==0) return true;
        // for every index, we can either go left or either go right, so we are exploring all possible paths
        
        queue<int>q;
        q.push(start);
        int n = arr.size();
        // vis array so that we dont visit same node twice
        int vis[n];
    
        memset(vis, false, sizeof vis);
             vis[start] = true;
        while(!q.empty())
        {
           int ind = q.front();
            q.pop();
            
          //  if(arr[ind]==0) return true;
            int left =  ind - arr[ind];
             if(left>=0 and vis[left]== false)
             {
                 if(arr[left]==0) return true;
                  vis[left] = true;
                q.push(left);
                
             }
            int right = ind + arr[ind];
            if(right <n and vis[right]== false)
            {
                if(arr[right]==0) return true;
                  vis[right]= true;
                q.push(right);
             
            }
        }
        return false;
                
    }
};