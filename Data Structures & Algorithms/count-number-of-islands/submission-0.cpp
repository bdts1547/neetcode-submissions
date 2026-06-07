class Solution {
   public:
    int LEN_ROW, LEN_COL, res = 0;
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        LEN_ROW = grid.size();
        LEN_COL = grid[0].size();
        // printf("START %d %d\n", LEN_ROW, LEN_COL);
        for (int r = 0; r < LEN_ROW; r++) {
            for (int c = 0; c < LEN_COL; c++) {
                // printf("%d %d %c\n", r, c, grid[r][c]);
                if (grid[r][c] == '1') {
                    res++;
                    // printf("position %d %d\n", r, c);
                    backtracking(grid, r, c);
                }
            }
        }
        return res;
    }

    void backtracking(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= LEN_ROW || c >= LEN_COL) {
            return;
        }

        if (grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';

        backtracking(grid, r + 1, c);  // down
        backtracking(grid, r - 1, c);  // up
        backtracking(grid, r, c + 1);  // right
        backtracking(grid, r, c - 1);  // left
    }
};
