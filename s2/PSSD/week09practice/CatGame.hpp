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

class CatGame
{
    public:
    int getNumber(vector<int> coordinates, int X)
    {
        sort(coordinates.begin(), coordinates.end());

        int result = INT_MAX;
        for (int i = 0; i < coordinates.size(); i++) {
            int temp = generate(coordinates, X, i);
            result = min(result, temp);
        }

        return result;
    }

    int generate(vector<int> coordinates, int X, int pos)
    {
        int left = INT_MAX;
        int right = INT_MIN;

        for (int i = 0; i < pos; i++) {
            coordinates[i] += X;
            left = min(left, coordinates[i]);
            right = max(right, coordinates[i]);
        }

        for (int i = pos; i < coordinates.size(); i++) {
            coordinates[i] -= X;
            left = min(left, coordinates[i]);
            right = max(right, coordinates[i]);
        }

        return right - left;
    }
};