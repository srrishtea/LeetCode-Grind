class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return; // Check for empty matrix
        int m = matrix[0].size();
        if (m == 0) return; // Check for empty matrix
        
        // Use vectors instead of C-style arrays
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // Step 1: Mark the rows and columns that should be zeroed
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Step 2: Update the matrix based on row and col markers
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
