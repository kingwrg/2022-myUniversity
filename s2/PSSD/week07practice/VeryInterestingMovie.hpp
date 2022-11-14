#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <climits>
#include <bitset>
#include <cmath>

using namespace std;

class VeryInterestingMovie
{
    public:
    int maximumPupils (vector<string> seats)
    {
        int result = 0;
        for (int i = 0; i < seats.size(); i++) {
            int c_y = 0;
            for (int j = 0; j < seats[i].size(); j++) {
                if (seats[i][j] == 'N') {
                    result += (c_y/2);
                    if (c_y % 2 != 0) result++;
                    c_y = 0;
                } else {
                    c_y++;
                }
            }
            result += (c_y/2);
            if (c_y % 2 != 0) result++;
        }

        return result;
    }
};