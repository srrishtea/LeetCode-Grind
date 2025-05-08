class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({0, 0, 0, 1});

        while (!pq.empty()) {
            auto top = pq.top();

            int time = top[0];
            int x = top[1];
            int y = top[2];
            int parity = top[3];

            pq.pop();

            moveTime[x][y] = -1;

            if (x == n - 1 && y == m - 1) {
                return time;
            }

            for (int d = 0; d < 4; d++) {
                int n_x = x + dx[d];
                int n_y = y + dy[d];

                if (n_x < 0 || n_y < 0 || n_x >= n || n_y >= m ||
                    moveTime[n_x][n_y] == -1) {
                    continue;
                }
                int time_n = max(moveTime[n_x][n_y], time);
                if (dist[n_x][n_y] > time_n + parity) {
                    dist[n_x][n_y] = time_n + parity;
                    pq.push({dist[n_x][n_y], n_x, n_y, (parity == 1) ? 2 : 1});
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};