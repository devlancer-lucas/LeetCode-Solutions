// Time:  O(8^(m * n - 1))
// Space: O(m * n)

// backtracking
class Solution {
public:
    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2},
                                                          {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};

        vector<vector<int>> result(m, vector<int>(n, -1));
        result[r][c] = 0;
        const function<bool(int, int, int)> backtracking = [&](int r, int c, int i) {
            if (i == m * n) {
                return true;
            }
            for (const auto& [dr, dc] : DIRECTIONS) {
                const int nr = r + dr, nc = c + dc;
                if (!(0 <= nr && nr < m && 0 <= nc && nc < n && result[nr][nc] == -1)) {
                    continue;
                }
                result[nr][nc] = i;
                if (backtracking(nr, nc, i + 1)) {
                    return true;
                }
                result[nr][nc] = -1;
            }
            return false;
        };

        backtracking(r, c, 1);
        return result;
    }
};
