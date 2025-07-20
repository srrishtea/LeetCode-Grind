class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    bool find(int ind, int i, int j, vector<vector<char>>& board, string& word) {
        if (ind == word.length()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '$') return false;
        if (board[i][j] != word[ind]) return false;

        char temp = board[i][j];
        board[i][j] = '$'; 

        for (int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d]; 
            if (find(ind + 1, ni, nj, board, word)) return true;
        }

        board[i][j] = temp; 
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (find(0, i, j, board, word)) 
                        return true;
                }
            }
        }
        return false;
    }
};
