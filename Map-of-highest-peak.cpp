class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater.at(0).size();
        vector<vector<int>> vis(n, vector<int>(m, -1));

        queue<array<int, 3>> q;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(isWater[i][j]) {
                    vis[i][j] = 0;
                    q.push({i, j, 0});
                }
            }
        }
        int dx[] = {0, 1, 0, -1, 0};
        int mx = 0;
        while(q.size()) {
            auto [x, y, d] = q.front(); q.pop();
            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dx[i+1];
                if(nx < n and ny < m and nx >= 0 and ny >= 0 and vis[nx][ny] == -1) {
                    vis[nx][ny] = d + 1;
                    q.push({nx, ny, d + 1});
                }
            }
        }

        return vis;
    }
};