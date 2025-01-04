class Solution {
private: 
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int rdir[], int cdir[]) {
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = row + rdir[i];
            int ncol = col + cdir[i];
            if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                dfs(nrow, ncol, grid, vis, rdir, cdir);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int rdir[] = {-1, 0, 1, 0};
        int cdir[] = {0, 1, 0, -1};

        // Perform DFS for all boundary cells
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1 && !vis[0][j]) {
                dfs(0, j, grid, vis, rdir, cdir);
            }
            if (grid[n-1][j] == 1 && !vis[n-1][j]) {
                dfs(n-1, j, grid, vis, rdir, cdir);
            }
        }
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                dfs(i, 0, grid, vis, rdir, cdir);
            }
            if (grid[i][m-1] == 1 && !vis[i][m-1]) {
                dfs(i, m-1, grid, vis, rdir, cdir);
            }
        }

        // Count enclaves
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};
