#include <string>
#include <vector>
#include <iostream>
using namespace std;

class CompositeS
{
    public:
    int howMany(int length)
    {
        if (length <= 1) return 0;
        if (length == 2) return 2;
        int result = howMany(length/2) + howMany(length/2 + 1);
        return result;
    }
};


