#include <string>
#include <vector>
#include <iostream>
using namespace std;

class ChickensAndCows
{
    public:
    vector<int> howMany(int heads, int legs)
    {
        vector<int> result = {};

        int cow = legs - heads*2;
        if (cow % 2 != 0 || cow < 0) return result;
        cow /= 2;

        int chick = heads - cow;
        if (chick < 0) return result;

        result.push_back(chick);
        result.push_back(cow);

        return result;
    }
};
// x and y
// x+y = head
// 2x+4y= leg