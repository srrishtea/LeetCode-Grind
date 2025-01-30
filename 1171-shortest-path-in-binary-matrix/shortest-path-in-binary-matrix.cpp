class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // If start or end is blocked, return -1
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) 
            return -1;

        // 8 possible movement directions
        vector<pair<int, int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},   
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}  
        };

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;

        q.push({0, 0});
        dis[0][0] = 1;  // Distance starts from 1 (including the starting cell)

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto it : directions) {
                int newx = x + it.first;
                int newy = y + it.second;

                // Check boundaries and if the new cell is valid
                if (newx >= 0 && newx < n && newy >= 0 && newy < m && 
                    grid[newx][newy] == 0 && dis[newx][newy] > dis[x][y] + 1) {
                    
                    q.push({newx, newy});
                    dis[newx][newy] = dis[x][y] + 1;
                }
            }
        }

        return (dis[n-1][m-1] == INT_MAX) ? -1 : dis[n-1][m-1];
    }
};
