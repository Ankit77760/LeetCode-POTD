//2812. Find the Safest Path in a Grid
/*
You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

A cell containing a thief if grid[r][c] = 1
An empty cell if grid[r][c] = 0
You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.

Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.

The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.

 

Example 1:


Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
Output: 0
Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).
Example 2:


Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.
Example 3:


Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
- The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.
 

Constraints:

1 <= grid.length == n <= 400
grid[i].length == n
grid[i][j] is either 0 or 1.
There is at least one thief in the grid.
*/

//Solution
class Solution {
public:
    const int adj[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    vector<vector<int>> BFSDis(const vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int, int>> q;
        vector<vector<int>> d(n, vector<int>(n, -1));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    d[i][j] = 0;
                    q.push({i, j});
                }

        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int newX = x + adj[dir][0];
                    int newY = y + adj[dir][1];

                    if (newX < 0 || newX >= n) continue;
                    if (newY < 0 || newY >= n) continue;
                    if (d[newX][newY] != -1) continue;
                    
                    d[newX][newY] = d[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }

        return d;
    }

    bool check(const vector<vector<int>>& d, int dis) {
        int n = d.size();

        if (d[0][0] < dis) 
            return false;

        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<vector<bool>> flag(n, vector<bool>(n, false));
        flag[0][0] = true;

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == n - 1 && y == n - 1) return true;

            for (int dir = 0; dir < 4; dir++) {
                int newX = x + adj[dir][0];
                int newY = y + adj[dir][1];

                if (newX < 0 || newX >= n) continue;
                if (newY < 0 || newY >= n) continue;
                if (flag[newX][newY]) continue;
                if (d[newX][newY] < dis) continue;
                    
                flag[newX][newY] = true;
                q.push({newX, newY});
            }
        }
        return false;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> d = BFSDis(grid);
        
        int l = 0;
        int r = 2 * n;
        int res = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (check(d, m)) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
        
    }
};