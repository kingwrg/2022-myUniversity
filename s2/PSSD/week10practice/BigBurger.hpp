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

class BigBurger
{
    public:
    int maxWait(vector<int> arrival, vector<int> service)
    {
        int time = 0;
        int result = 0;
        int n = arrival.size();

        for (int i = 0; i < n; i++) {
            if (i > 0) result = max(result, time - arrival[i]);
            if (time < arrival[i]) time = arrival[i];
            time += service[i];
        }

        return result;
    }
};