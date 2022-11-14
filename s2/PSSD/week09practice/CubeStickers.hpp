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

class CubeStickers
{
    public:
    string isPossible(vector<string> sticker)
    {
        sort(sticker.begin(), sticker.end());

        int count = 2;
        for (int i = 2; i < sticker.size(); i++) {
            if (sticker[i] != sticker[i-1] || sticker[i] != sticker[i-2]) count++;
        }

        if (count >= 6) return "YES";
        return "NO"; 
    }
};