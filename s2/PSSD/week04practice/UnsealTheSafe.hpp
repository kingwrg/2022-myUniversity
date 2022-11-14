#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class UnsealTheSafe
{
    public:
    long countPasswords(int N) 
    {
        long d[31][10];

        for (int i = 0; i < 10; i++) {
            d[1][i] = 1;
        }

        for (int i = 2; i <= N; i++) {
            d[i][0] = d[i-1][7];
            d[i][1] = d[i-1][2] + d[i-1][4];
            d[i][2] = d[i-1][1] + d[i-1][5] + d[i-1][3];
            d[i][3] = d[i-1][2] + d[i-1][6];
            d[i][4] = d[i-1][1] + d[i-1][5] + d[i-1][7];
            d[i][5] = d[i-1][2] + d[i-1][4] + d[i-1][6] + d[i-1][8];
            d[i][6] = d[i-1][3] + d[i-1][5] + d[i-1][9];
            d[i][7] = d[i-1][4] + d[i-1][8] + d[i-1][0];
            d[i][8] = d[i-1][7] + d[i-1][5] + d[i-1][9];
            d[i][9] = d[i-1][6] + d[i-1][8];
        }

        long result = 0;
        for (int i = 0; i < 10; i++) {
            result += d[N][i];
        }

        return result;
    }
};