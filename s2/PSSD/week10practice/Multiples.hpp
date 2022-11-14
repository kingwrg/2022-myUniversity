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

class Multiples
{
    public:
    int number(int min, int max, int factor)
    {
        int result = 0;
        for (int i = min; i <= max; i++)
            result += i%factor == 0 ? 1 : 0;
        
        return result;
    }
};