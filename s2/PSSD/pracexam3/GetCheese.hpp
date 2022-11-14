#include <iostream>
#include <vector>
#include <string>

using namespace std;

class GetCheese
{
    public:
    vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int rows, cols;

    vector<int> getRat(vector<string> maze) 
    {
        vector<int> result (2, 0);
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (maze[r][c] == 'R') {
                    result[0] = r;
                    result[1] = c;
                    break;
                }
            }
        }
        return result;
    }

    bool isDecision(vector<string> maze, vector<vector<int>> check, int x, int y)
    {
        int count = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;
            if (check[nx][ny] == 1) continue;
            if (maze[nx][ny] == '.' || maze[nx][ny] == '*') count++;
        }

        return count >= 2;
    }

    int dfs(vector<string> maze, vector<vector<int>> check, int x, int y, int dec) {
        // cout << x << " " << y << " " << dec << endl;
        if (x < 0 || x >= rows || y < 0 || y >= cols) return -1;
        
        if (maze[x][y] == 'X') return -1;

        if (check[x][y] == 1) return -1;
        check[x][y] = 1;

        if (maze[x][y] == '*') return dec;

        if (isDecision(maze, check, x, y)) dec++;
        // cout << isDecision(maze, check, x, y) << endl;

        int result = -1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            result = dfs(maze, check, nx, ny, dec);
            // cout << result << endl;
            if (result != -1) break;
        } 
        return result;
    }

    int	decisions(vector<string> maze)
    {
        rows = maze.size();
        cols = maze[0].length();

        // cout << rows << " " << cols << endl;

        vector<vector<int>> check (rows, vector<int> (cols, 0));
        vector<int> rat = getRat(maze);

        return dfs(maze, check, rat[0], rat[1], 0);
    }
};