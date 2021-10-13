class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n, false);
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            int room = q.front();
            q.pop();
            visited[room] = true;
            for(int enter : rooms[room])
            {
                if(!visited[enter])
                    q.push(enter);
            }
            
        }
        for(int i=0;i<n;i++)
            if(visited[i]==false) return false;
       return true;
    }
};