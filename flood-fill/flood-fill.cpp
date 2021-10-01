class Solution {
public:
        
  void dfs(int sr, int sc, int oldColour, int newColour, vector<vector<int>>& image) {
        // getting exit cases out of the way first: out of boundaries
        if (sr < 0 || sc < 0 || sr == image.size() || sc == image[0].size()
            // or different colour
            || image[sr][sc] != oldColour) return;
        image[sr][sc] = newColour;
        dfs(sr - 1, sc, oldColour, newColour, image);
        dfs(sr + 1, sc, oldColour, newColour, image);
        dfs(sr, sc - 1, oldColour, newColour, image);
        dfs(sr, sc + 1, oldColour, newColour, image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColour) {
        // we call it only if the new colour is different; would loop infinitely otherwise
        if (image[sr][sc] != newColour) dfs(sr, sc, image[sr][sc], newColour, image);
        return image;
    }
};