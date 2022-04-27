class Solution {
public:

void dfs(int i, vector<int>& vis, vector<int>& indices, vector<char>& chars, string& s, vector<vector<int>>& adj)
{
    // Storing the nodes and also the string of this component
	indices.push_back(i);
	chars.push_back( s[i]);
	vis[i] = 1;

	for (auto node : adj[i])
	{
		if (!vis[node])
		{
			dfs(node, vis, indices, chars, s, adj);
		}
	}
}

string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
	// Creating a Graph with the given pairs 
	int n = s.size();
	vector<vector<int>> adj(n);
    
	for (auto p : pairs)
	{
		int src = p[0], dst = p[1];
		adj[src].push_back(dst);
		adj[dst].push_back(src);
	}

	// Finding the components for the given graph
	vector<int> vis(n, 0);
	for (int i = 0; i < n; ++i)
	{
		if (!vis[i])
		{
			vector<int>indices;
            vector<char>chars;
            
			//string componentString;
			dfs(i, vis, indices, chars, s, adj);
            
            // Sorting the nodes nad componentString to make the nodes accending and component string in lexicographically order
			sort(indices.begin(), indices.end());
			sort(chars.begin(), chars.end());
            
            // Replace the new lexicographically string of the component with the old string at the indices of the components
			for (int k = 0; k < chars.size(); k++)
			{
				s[indices[k]] = chars[k];
			}
		}
	}
    
    // Finally Return the answer
	return s;
}
};