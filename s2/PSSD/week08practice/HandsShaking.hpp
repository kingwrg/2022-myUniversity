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

class HandsShaking
{
    public:
    long countPerfect(int n) 
    {
        vector<long> dp (51, 0);
        dp[0] = 1;

        for (int i = 2; i <= n; i+=2) {
            for (int j = 0; j <= i-2; j+=2) {
                dp[i] += dp[j] * dp[i-j-2];
            }
        }

        return dp[n];
    }
};