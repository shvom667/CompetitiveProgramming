#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

const int MOD = 998244353;
using namespace std;

// Directions for 4 adjacent cells (up, down, left, right)
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

// Function to check if a cell is inside the grid
bool in_bounds(int x, int y, int H, int W) {
    return x >= 0 && x < H && y >= 0 && y < W;
}

// Function to perform BFS and count valid configurations
bool bfs(int start_x, int start_y, const vector<vector<char>>& grid, 
         vector<vector<int>>& color, vector<vector<bool>>& visited, int H, int W) {
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    color[start_x][start_y] = 1; // Start coloring with '1'
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // Try to color the adjacent cells with a different color
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (in_bounds(nx, ny, H, W) && !visited[nx][ny]) {
                if (grid[nx][ny] == '?') {
                    // Color the adjacent cell with a different color
                    color[nx][ny] = 3 - color[x][y]; // Alternate between 1 and 2
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            // If an adjacent cell has a fixed value, check for conflict
            if (in_bounds(nx, ny, H, W) && grid[nx][ny] != '?' && grid[nx][ny] - '0' == color[x][y]) {
                return false; // Conflict found, return false
            }
        }
    }
    return true;
}

int solve(int H, int W, vector<vector<char>>& grid) {
    vector<vector<int>> color(H, vector<int>(W, -1));  // -1 indicates no color
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    int result = 1;

    // Traverse all cells in the grid
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == '?' && !visited[i][j]) {
                // If the cell is unvisited and a '?', start BFS from here
                if (!bfs(i, j, grid, color, visited, H, W)) {
                    return 0;  // If any contradiction found, return 0
                }
                result = (result * 3) % MOD;  // Each connected component can be colored in 3 ways
            }
        }
    }
    return result;
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> grid(H, vector<char>(W));

    // Read the grid
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    // Call the solve function and output the result
    cout << solve(H, W, grid) << endl;

    return 0;
}
