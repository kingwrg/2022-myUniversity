#include <string>
#include <set>
#include <iostream>

using namespace std;

class EggCartons
{
    public:
    int minCartons(int n)
    {
        for (int six = 0; six < 17; six++) {
            for (int eight = 12; eight >= 0; eight--) {
                if (n == six*6 + eight*8) return six + eight;
            }
        }
        
        return -1;
    }
};