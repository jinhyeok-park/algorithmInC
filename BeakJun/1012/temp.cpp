#include <vector>
#include <queue>

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void visit(vector<vector<int>>& map, int r, int c) {
    queue<pair<int, int>> pos;
    map[r][c] = 0;
    pos.push({r, c});
    while (!pos.empty()) {
        pair<int, int> curr = pos.front(); pos.pop_front();

        for (int i = 0; i < 4; i++) {
            int nr = curr.first;
            int nc = curr.second;
            if (nr < 0 || nc < 0 || nr > map.size() || nc > map[0].size() || map[nr][nc] != 1)
                continue;
            map[nr][nc] = 0;
            pos.push({nr, nc});
        }
    }
}

int count_land(vector<vector<int>> map) {
    int res = 0;
    int n = map.size();
    int m = map[0].size();

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (map[r][c] == 1) {
                visit(map, r, c);
                res++;
            }
        }
    }
    return res;
}