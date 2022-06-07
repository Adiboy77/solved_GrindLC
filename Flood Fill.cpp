class Solution {
public:
    /*BFS: iterative
     int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        int startColor = image[sr][sc];
        if (startColor == newColor) return image;
        int e[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        image[sr][sc] = newColor;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = r + e[k][0];
                int y = c + e[k][1];
                if (x >= 0 && y >= 0 && x < m && y < n && image[x][y] == startColor) {
                    image[x][y] = newColor;
                    q.push(make_pair(x, y));
                }
            }
        }
        return image;
    */
    //DFS: recursive
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor) dfs(image, sr, sc, color, newColor);
        return image;
    }
void dfs(vector<vector<int>>& image, int r, int c, int color, int newColor) {
        if (image[r][c] == color) {
            image[r][c] = newColor;
            if (r >= 1) dfs(image, r-1, c, color, newColor);
            if (c >= 1) dfs(image, r, c-1, color, newColor);
            if (r+1 < image.size()) dfs(image, r+1, c, color, newColor);
            if (c+1 < image[0].size()) dfs(image, r, c+1, color, newColor);
        }
    }
};
