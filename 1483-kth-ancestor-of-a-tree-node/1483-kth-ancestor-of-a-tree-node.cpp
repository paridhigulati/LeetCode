class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        // binary lifting
        parentTable = vector<vector<int>>(n, vector<int>(32));
        // 2^0th parent of a node
        for (int i = 0; i < n; ++i) 
            parentTable[i][0] = parent[i];
        // populate table: [node][2^kth ancestor of node]
        for (int j = 1; j < 32; ++j) {
			// look through each row
            for (int i = 0; i < n; ++i) {
				// either node has no more ancestors or can record the ancestor of the ancestor of the previous node
                parentTable[i][j] = (parentTable[i][j-1] == -1) ? -1 : parentTable[parentTable[i][j-1]][j-1];
			}
        }
    }
    
    int getKthAncestor(int node, int k) {
        int i = 0;
		// search the table using the bits of k
        while (k > 0) {
            if (k & 1) {
                if (parentTable[node][i] == -1)
                    return -1;
                // move node up to the 2^ith ancestor of where it is now if it exists
                node = parentTable[node][i];
            }
            k >>= 1;
            ++i;
        }
        return node;
    }
private:
    vector<vector<int>> parentTable;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */