#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class EmergencyDrill
{
    public:
    int reportTime(vector<int> leaders)
    {
        int result = 0;

        map<int, int> call;
        for (int i = 1; i < leaders.size(); i++) {
            if (call.count(leaders[i])) { 
                call[leaders[i]] = 0;
            } else {
                result--;
            }
            call[leaders[i]]++;
            result++;
        }

        return result;
    }
};