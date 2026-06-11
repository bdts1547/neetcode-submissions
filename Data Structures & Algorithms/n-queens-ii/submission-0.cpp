class Solution {
public:
    int totalNQueens(int n) {
        unordered_set<int> posDiag, negDiag, col;
        int res = 0;
        vector<string> chess(n, string(n, '.')); /// ["..", ".."]
        backtracking(0, chess, res, posDiag, negDiag, col);
        return res;
    }

    void backtracking(int r, vector<string>& chess, int& res, 
    unordered_set<int>& posDiag, unordered_set<int>& negDiag, unordered_set<int>& col) {
        if (r >= chess.size()) {
            res++;
            return;
        }

        for (int c = 0; c < chess.size(); c++) {
            if (!posDiag.count(r+c) && !negDiag.count(r-c) && !col.count(c)) {
                chess[r][c] = 'Q';
                posDiag.insert(r+c);
                negDiag.insert(r-c);
                col.insert(c);
                backtracking(r+1, chess, res, posDiag, negDiag, col);
                chess[r][c] = '.';
                posDiag.erase(r+c);
                negDiag.erase(r-c);
                col.erase(c);
            }
        }
    }
};