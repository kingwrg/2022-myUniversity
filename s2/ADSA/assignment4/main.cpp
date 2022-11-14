#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class UnionFind
{
    private:
    int n;
    vector<int> parent;

    public:
    UnionFind(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    int find(int x)
    {
        if (parent[x] == x) {
            return x;
        }
        return find(parent[x]);
    }

    void unionXY(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            parent[px] = py;
        }
    }
};

class CitiesRoads
{
    private:
    vector<vector<int>> country;
    vector<vector<int>> build;
    vector<vector<int>> destroy;
    int len;
    UnionFind* graph;

    int getVal(char c) 
    {
        if (isdigit(c)) {
            return c - '0';
        } else if (isupper(c)) {
            return c - 'A';
        }
        return 26 + c - 'a';
    }

    void fillMatrix(string s, vector<vector<int>> &matrix, int n)
    {
        int r = 0;
        int c = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ',') {
                r++;
                c = 0;
            } else {
                matrix[r][c] = getVal(s[i]);
                c++;
            }

        }
    }

    int costDestroyCycle()
    {
        vector<vector<int>> can_destroy;
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                if (country[i][j] == 1) 
                    can_destroy.push_back({i, j, destroy[i][j]});
            }
        }

        sort(can_destroy.begin(), can_destroy.end(), [] (const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        });

        int result = 0;
        for (int i = 0; i < can_destroy.size(); i++) {
            int x = can_destroy[i][0];
            int y = can_destroy[i][1];
            int cost = can_destroy[i][2];

            int parent_x = graph->find(x);
            int parent_y = graph->find(y);

            if (parent_x == parent_y) 
                result += cost;
            else 
                graph->unionXY(x, y);
        }

        return result;
    }

    int costBuildPath()
    {
        vector<vector<int>> build_path;
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                build_path.push_back({i, j, build[i][j]});
            }
        }

        sort(build_path.begin(), build_path.end(), [] (const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        int result = 0;
        for (int i = 0; i < build_path.size(); i++) {
            int x = build_path[i][0];
            int y = build_path[i][1];
            int cost = build_path[i][2];

            int parent_x = graph->find(x);
            int parent_y = graph->find(y);

            if (parent_x != parent_y) {
                result += cost;
                graph->unionXY(x, y);
            }
        }

        return result;
    }

    public:
    CitiesRoads(vector<string> moves, int n)
    {
        country = vector<vector<int>> (n, vector<int> (n, 0));
        build = vector<vector<int>> (n, vector<int> (n, 0));
        destroy = vector<vector<int>> (n, vector<int> (n, 0));
        len = n;

        fillMatrix(moves[0], country, n);
        fillMatrix(moves[1], build, n);
        fillMatrix(moves[2], destroy, n);

        graph = new UnionFind(n);
    }

    int reconstuction()
    {
        int temp1 = costDestroyCycle();
        int temp2 = costBuildPath();
        return temp1 + temp2;
    }

    void printMatrix()
    {
        cout << "country:" << endl;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                cout << country[i][j] << " ";
            }
            cout << endl;
        }

        cout << "build:" << endl;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                cout << build[i][j] << " ";
            }
            cout << endl;
        }

        cout << "destroy:" << endl;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                cout << destroy[i][j] << " ";
            }
            cout << endl;
        }
    }
};

vector<string> getMoves(string s)
{
    vector<string> moves;

    stringstream ss(s);
    string m;
    
    while (ss >> m) {
        moves.push_back(m);
    }

    return moves;
}

int main() 
{
    string s;
    getline(cin, s);

    vector<string> moves = getMoves(s);
    int i;
    for (i = 0; i < moves[0].size(); i++) {
        if (moves[0][i] == ',') break;
    }

    CitiesRoads* test = new CitiesRoads(moves, i);

    cout << test->reconstuction() << endl;
}
