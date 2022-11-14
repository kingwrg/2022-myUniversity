#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

class TaliluluCoffee
{
    public:
    int maxTip(vector<int> tips)
    {
        sort(tips.begin(), tips.end(), []
            (const int&a, const int&b) {
                return a > b;
            });

        int result = 0;
        for (int i = 0; i < tips.size(); i++) {
            if (tips[i] - i < 0) continue;
            result += tips[i] - i;
        }

        return result;
    }
};