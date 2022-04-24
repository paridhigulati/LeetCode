class Solution {
public:
  
        int countLatticePoints(vector<vector<int>>& circles) {
        int ans = 0; 
        for (int x = 0; x <= 200; ++x) 
            for (int y = 0; y <= 200; ++y) {
                bool found = false; 
                for (auto& c : circles) 
                    if (pow(x-c[0], 2) + pow(y-c[1], 2) <= pow(c[2], 2)) 
                        found = true; 
                if (found) ++ans; 
            }
        return ans; 
    }
};
   