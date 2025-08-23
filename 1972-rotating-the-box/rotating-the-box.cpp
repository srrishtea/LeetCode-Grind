class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        vector<vector<char>> box(m, vector<char>(n, '.'));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                box[i][j] = boxGrid[n - 1 - j][i];
            }
        }

        for (int col = 0; col < n; col++) {
            int write = m - 1;
            for (int row = m - 1; row >= 0; row--) {
                if (box[row][col] == '*') {
                    write = row - 1;
                } else if (box[row][col] == '#') {
                    if (row != write) {
                        box[write][col] = '#';
                        box[row][col] = '.';
                    }
                    write--;
                }
            }
        }

        return box;
    }
};
