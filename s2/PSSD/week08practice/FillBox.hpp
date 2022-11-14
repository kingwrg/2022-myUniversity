#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class FillBox
{
    public:
    int minCubes(int length, int width, int height, vector<int> cubes)
    {
        long l = length;
        long w = width;
        long h = height;
        long count = 0;

        int result = 0;

        for (int i = cubes.size() - 1; i >= 0 ; i--) {
            long side = 1L << i;
            
            long amount = (l/side) * (w/side) * (h/side);
            amount -= count;

            if (amount > cubes[i]) amount = cubes[i];

            count = (count + amount) * 8;
            
            result += amount;
        }

        if (count < 8*l*w*h) return -1;

        return result;
    }
};