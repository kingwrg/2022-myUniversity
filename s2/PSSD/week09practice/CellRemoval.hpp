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

class CellRemoval
{
    public:
    int cellsLeft(vector<int> parent, int deletedCell)
    {
        if (parent[deletedCell] == -1) return 0;
        set<int> p;

        int d = 0;
        for (int i = 0; i < parent.size(); i++) {
            if (isDeleted(parent, deletedCell, i)) d++;
            else p.insert(parent[i]);
        }

        return parent.size() - d - p.size() + 1;
    }

    bool isDeleted(vector<int> parent, int deletedCell, int pos)
    {
        if (parent[pos] == deletedCell || pos == deletedCell) return true;
        if (parent[pos] == -1) return false;
        
        return isDeleted(parent, deletedCell, parent[pos]);
    }
};