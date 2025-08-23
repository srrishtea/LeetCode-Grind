class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> a(m, vector<int>(n, 1)), b(m, vector<int>(n, 1)),
            c(m, vector<int>(n, 1)), d(m, vector<int>(n, 1));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int v = grid[i][j];
                if (v == 1) {
                    res = 1;
                    continue;
                }
                if (i > 0 && j > 0 && grid[i - 1][j - 1] == 2 - v) {
                    a[i][j] = a[i - 1][j - 1] + 1;
                }
                if (i > 0 && j + 1 < n && grid[i - 1][j + 1] == 2 - v) {
                    b[i][j] = b[i - 1][j + 1] + 1;
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                int v = grid[i][j];
                if (v == 1) {
                    continue;
                }
                if (i + 1 < m && j > 0 && grid[i + 1][j - 1] == 2 - v) {
                    c[i][j] = c[i + 1][j - 1] + 1;
                }
                if (i + 1 < m && j + 1 < n && grid[i + 1][j + 1] == 2 - v) {
                    d[i][j] = d[i + 1][j + 1] + 1;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int v = grid[i][j];
                if (v == 1) {
                    continue;
                }
                if ((a[i][j] % 2 == 0 && v == 0) ||
                    (a[i][j] % 2 == 1 && v == 2)) {
                    int ki = i - a[i][j];
                    int kj = j - a[i][j];
                    if (ki >= 0 && kj >= 0 && ki < m && kj < n &&
                        grid[ki][kj] == 1) {
                        int mVal = c[i][j];
                        res = max(res, mVal + a[i][j]);
                    }
                }
                if ((b[i][j] % 2 == 0 && v == 0) ||
                    (b[i][j] % 2 == 1 && v == 2)) {
                    int ki = i - b[i][j];
                    int kj = j + b[i][j];
                    if (ki >= 0 && kj >= 0 && ki < m && kj < n &&
                        grid[ki][kj] == 1) {
                        int mVal = a[i][j];
                        res = max(res, mVal + b[i][j]);
                    }
                }
                if ((c[i][j] % 2 == 0 && v == 0) ||
                    (c[i][j] % 2 == 1 && v == 2)) {
                    int ki = i + c[i][j];
                    int kj = j - c[i][j];
                    if (ki >= 0 && kj >= 0 && ki < m && kj < n &&
                        grid[ki][kj] == 1) {
                        int mVal = d[i][j];
                        res = max(res, mVal + c[i][j]);
                    }
                }
                if ((d[i][j] % 2 == 0 && v == 0) ||
                    (d[i][j] % 2 == 1 && v == 2)) {
                    int ki = i + d[i][j];
                    int kj = j + d[i][j];
                    if (ki >= 0 && kj >= 0 && ki < m && kj < n &&
                        grid[ki][kj] == 1) {
                        int mVal = b[i][j];
                        res = max(res, mVal + d[i][j]);
                    }
                }
            }
        }
        return res;
    }
};