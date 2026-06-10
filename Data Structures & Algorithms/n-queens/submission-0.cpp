class Solution {
public:
    unordered_set<int> negDiag, posDiag, col;
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board (n, string(n,  '.'));
        backtracking(0, board,res);
        return res;
    }

    void backtracking(int r, vector<string>& board, vector<vector<string>>& res) {
        if (r >= board.size()) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < board.size(); c++) {
            if (!negDiag.count(r-c) && !posDiag.count(r+c) && !col.count(c)) {
                board[r][c] = 'Q';
                negDiag.insert(r-c);
                posDiag.insert(r+c);
                col.insert(c);
                backtracking(r + 1, board, res);
                board[r][c] = '.';
                negDiag.erase(r-c);
                posDiag.erase(r+c);
                col.erase(c);
            }
        }


    }
};
