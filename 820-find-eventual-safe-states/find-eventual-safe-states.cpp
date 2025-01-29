class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<vector<int>> revgraph(v);  // Corrected declaration
        vector<int> indeg(v, 0);          // Corrected declaration
        
        // Reverse the graph and calculate in-degree
        for (int i = 0; i < v; i++) {
            for (auto it : graph[i]) {
                revgraph[it].push_back(i);
                indeg[i]++;
            }
        }

        queue<int> q;
        vector<int> safenodes;

        // Push all terminal nodes (indegree = 0) into the queue
        for (int i = 0; i < v; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        // Process the queue (BFS)
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safenodes.push_back(node); // Add to result

            for (auto it : revgraph[node]) {
                indeg[it]--;
                if (indeg[it] == 0) q.push(it);
            }
        }

        sort(safenodes.begin(), safenodes.end()); // Ensure sorted order
        return safenodes;
    }
};
