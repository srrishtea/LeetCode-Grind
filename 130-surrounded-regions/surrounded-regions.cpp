class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // Ensure in bounds and valid cell before DFS recursion
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                board[nrow][ncol] == 'O' && vis[nrow][ncol] == 0) {
                dfs(nrow, ncol, board, vis);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return; // Handle edge case of empty board
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Mark boundary-connected 'O's
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, board, vis);
            }
            if (!vis[n-1][j] && board[n-1][j] == 'O') {
                dfs(n-1, j, board, vis);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, board, vis);
            }
            if (!vis[i][m-1] && board[i][m-1] == 'O') {
                dfs(i, m-1, board, vis);
            }
        }

        // Final replacement of surrounded regions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X'; // Surrounded 'O'
                } else if (vis[i][j]) {
                    board[i][j] = 'O'; // Restore boundary-connected 'O'
                }
            }
        }
    }
};
