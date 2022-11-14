#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

class CountExpressions
{
    public:
    int calcExpressions(int x, int y, int val)
    {
        return calcExpressionsHelper(x, 1, y, 2, val, 0, x) + calcExpressionsHelper(x, 2, y, 1, val, 0, y);
    }

    int calcExpressionsHelper(int x, int c_x, int y, int c_y, int val, int result, int accumulate)
    {
        if (c_x == 0 && c_y == 0) {
            if (accumulate == val) return 1;
            return 0;
        }

        int temp = result;
        if (c_x > 0) {
            temp += calcExpressionsHelper(x, c_x-1, y, c_y, val, result, accumulate+x);
            temp += calcExpressionsHelper(x, c_x-1, y, c_y, val, result, accumulate-x);
            temp += calcExpressionsHelper(x, c_x-1, y, c_y, val, result, accumulate*x);
        } 
        
        if (c_y > 0) {
            temp += calcExpressionsHelper(x, c_x, y, c_y-1, val, result, accumulate+y);
            temp += calcExpressionsHelper(x, c_x, y, c_y-1, val, result, accumulate-y);
            temp += calcExpressionsHelper(x, c_x, y, c_y-1, val, result, accumulate*y);
        }

        return temp;
    }
};