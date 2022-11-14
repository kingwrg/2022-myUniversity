#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class RGBStreet
{
    public:
    int estimateCost(vector<string> houses) 
    {
        int costs[3][20];
        int n = houses.size();

        sscanf(houses[0].c_str(), "%d %d %d", &costs[0][0], &costs[1][0], &costs[2][0]);
        for (int i = 1; i < n; i++) {
            int r, b, g;
            sscanf(houses[i].c_str(), "%d %d %d", &r, &b, &g);

            costs[0][i] = r + min(costs[1][i-1], costs[2][i-1]);
            costs[1][i] = b + min(costs[0][i-1], costs[2][i-1]);
            costs[2][i] = g + min(costs[0][i-1], costs[1][i-1]);
        }

        return min(min(costs[0][n-1], costs[1][n-1]), costs[2][n-1]);
    }
};