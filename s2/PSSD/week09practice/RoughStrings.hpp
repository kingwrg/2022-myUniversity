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

class RoughStrings
{
    public:
    int minRoughness(string s, int n)
    {
        vector<int> count (26, 0);
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
        }

        int result = 51;
        for (int mn = 0; mn < s.length() + 1; mn++) {
            for (int mx = mn; mx < s.length() + 1; mx++) {
                if (mx - mn > result) continue;

                int remove = 0;
                for (int i = 0; i < 26; i++) {
                    if (count[i] > mx) remove += count[i] - mx;
                    else if (count[i] < mn) remove += count[i];
                }

                if (remove <= n) result = mx - mn; 
            }
        }

        return result;
    }

};