#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class LemonGate 
{
    public: 
    int maxNumber(vector <int> lemons) 
    {
        int n = lemons.size();

        vector<int> dp (n, 0);

        for (int i = 0; i < n; i++) {
            if (i < 2) {
                dp[i] = lemons[i];
            } else  {
                dp[i] = lemons[i] + max(dp[i-2], dp[i-3]);
            }
        }

        return max(dp[n-1], dp[n-2]);
    }
};