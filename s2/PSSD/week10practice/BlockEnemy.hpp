#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

class BlockEnemy
{
    public:
    vector<vector<int>> graph;
    vector<bool> enemy;
    int cost, remove_a, remove_b;
    
    bool path(int src, int idx) 
    {
        bool res = (enemy[idx] && src != idx);

        for (int i = 0; i < graph.size(); i++) {
            if (graph[idx][i] == 0) continue;

            int c = graph[idx][i];
            graph[idx][i] = graph[i][idx] = 0;

            if (path(src, i)) {
                if (c < cost) {
                    cost = c;
                    remove_a = idx;
                    remove_b = i;
                }
                res = true;
            }

            graph[idx][i] = graph[i][idx] = c;
        }
        
        return res;
    }

    int minEffort(int N, vector<string> roads, vector<int> occupiedTowns)
    {
        graph = vector<vector<int>> (N, vector<int> (N, 0));
        enemy = vector<bool> (N, false);

        for (int i = 0; i < roads.size(); i++) {
            int a, b, e;
            sscanf(roads[i].c_str(), "%d %d %d", &a, &b, &e);
            graph[a][b] = e;
            graph[b][a] = e;
        }

        for (int i = 0; i < occupiedTowns.size(); i++) {
            enemy[occupiedTowns[i]] = true;
        }

        int res = 0;
        for (int i = 0; i < N; i++) {
            if (!enemy[i]) continue;
            while (true) {
                cost = INT_MAX;
                if (!path(i,i)) break;

                res += cost;
                graph[remove_a][remove_b] = graph[remove_b][remove_a] = 0;
            }
        }

        return res;
    }
};