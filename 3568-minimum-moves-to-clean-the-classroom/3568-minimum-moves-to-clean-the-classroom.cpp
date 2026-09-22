class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        int cnt = 0;

        // Give each litter an index
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        int full = (1 << cnt) - 1;

        // state = {row, col, collectedMask, energyLeft}
        queue<array<int, 4>> q;

        q.push({sr, sc, 0, energy});

        // visited[row][col][mask][energy]
        bool visited[20][20][1 << 10][51] = {};

        visited[sr][sc][0][energy] = true;

        int steps = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [r, c, mask, e] = q.front();
                q.pop();

                // All litter collected
                if (mask == full)
                    return steps;

                // No energy
                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nm = mask;

                    // Found litter
                    if (classroom[nr][nc] == 'L') {
                        nm |= (1 << id[nr][nc]);
                    }

                    // Reset energy
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    if (!visited[nr][nc][nm][ne]) {

                        visited[nr][nc][nm][ne] = true;

                        q.push({nr, nc, nm, ne});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};