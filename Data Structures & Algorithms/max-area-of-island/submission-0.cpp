class Solution {
public:
    int ROWS, COLS, res = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        int area = 0;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c]) {
                    res++;
                    int tmp = 0;
                    backtracking(grid, r, c, tmp);
                    area = max(area, tmp);
                }
            }
        }

        return area;
    }

    void backtracking(vector<vector<int>>& grid, int r, int c, int& area) {
        if (r < 0 || c < 0 || c >= COLS || r >= ROWS || !grid[r][c]) return;
        area++;
        grid[r][c] = 0;

        backtracking(grid, r + 1, c, area);
        backtracking(grid, r - 1, c, area);
        backtracking(grid, r, c + 1, area);
        backtracking(grid, r, c - 1, area);
    }
};