#include <iostream>
#include <string>

using namespace std;

class StrangeComputer
{
    public:
    int setMemory(string mem) 
    {
        int n = mem.length();
        int result = 0;
        if (mem.at(0) == '1') result++;
        for (int i = 1; i < n; i++) 
        {
            if (mem.at(i) != mem.at(i-1)) result++;
        }
        return result;
    }
};