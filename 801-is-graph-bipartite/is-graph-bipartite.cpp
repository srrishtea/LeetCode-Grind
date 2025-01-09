class Solution {
private:
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = col; 
        
        // Traverse adjacent nodes
        for (auto it : graph[node]) {
            // If uncolored
            if (color[it] == -1) {
                if (!dfs(it, !col, color, graph)) return false; 
            }
            // If previously colored and have the same color
            else if (color[it] == col) {
                return false; 
            }
        }
        
        return true; 
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size(); // Number of vertices
        vector<int> color(V, -1); // Initialize colors as -1
        
        // For all connected components
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, color, graph)) 
                    return false; 
            }
        }
        return true; 
    }
};
