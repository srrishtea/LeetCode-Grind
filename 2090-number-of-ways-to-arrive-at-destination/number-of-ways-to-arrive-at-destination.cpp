class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);

        // Build adjacency list
        for (auto& it : roads) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Min-heap priority queue for Dijkstra's Algorithm
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> time(n, LLONG_MAX); // Stores shortest time to reach each node
        vector<int> ways(n, 0); // Stores number of ways to reach each node

        pq.push({0, 0});  // {time, node}
        time[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto [t, node] = pq.top();
            pq.pop();

            if (t > time[node]) continue; // Ignore outdated entries

            for (auto& [adjNode, edgeTime] : adj[node]) {
                long long newTime = t + edgeTime;

                if (newTime < time[adjNode]) {
                    time[adjNode] = newTime;
                    ways[adjNode] = ways[node]; // New shortest path found
                    pq.push({newTime, adjNode});
                } else if (newTime == time[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD; // Add new way
                }
            }
        }

        return ways[n - 1];
    }
};
