#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DinnerLighting 
{
    public:
    vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int rows, cols;

    vector<vector<int>> getLamps(vector<string> roomPlan) 
    {
        vector<vector<int>> result;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (roomPlan[r][c] == 'O') {
                    result.push_back(vector<int> {r, c});
                }
            }
        }
        return result;
    }
    
    bool boundary(int x, int y) 
    {
        return (x < 0 || x >= rows || y < 0 || y >= cols);
    }

    void dfs(vector<string>& roomPlan, int x, int y) 
    {
        // cout << x << " " << y << " " << dec << endl;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            while (!boundary(nx, ny) && roomPlan[nx][ny] != '#') {
                roomPlan[nx][ny] = '*';
                nx += dir[i][0];
                ny += dir[i][1];
            } 
        }
    }

    int	countDarkSquares (int R, int C, vector<string> roomPlan) 
    {
        rows = R;
        cols = C;

        vector<vector<int>> lamps = getLamps(roomPlan);
        for (int i = 0; i < lamps.size(); i++) {
            dfs(roomPlan, lamps[i][0], lamps[i][1]);
        }

        int result = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // cout << roomPlan[r][c] << " ";
                if (roomPlan[r][c] == '.') result++;
            }
            // cout << endl;
        }

        return result;
    }
};