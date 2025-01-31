class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // Initialize distance array
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Queue for BFS: {stops, {node, cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        // Perform BFS
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // If stops exceed k, skip further exploration
            if (stops > k) {
                continue;
            }

            // Explore neighbors
            for (auto& iter : adj[node]) {
                int adjNode = iter.first;
                int edW = iter.second;

                // Relax the edge if a better path is found
                if (cost + edW < dist[adjNode] && stops <= k) {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}});
                }
            }
        }

        // If the destination is unreachable, return -1
        if (dist[dst] == INT_MAX) {
            return -1;
        }
        return dist[dst];
    }
};