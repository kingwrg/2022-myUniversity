#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

class ColorfulRabbits
{
    public:
    int getMinimum(vector<int> replies)
    {
        map<double, double> group;
        for (int i = 0; i < replies.size(); i++) {
            if (group.count(replies[i]) == 0) {
                group[replies[i]] = 0;
            }
            group[replies[i]]++;
        }

        int result = 0;

        for (pair<double, double> rabbits : group) {
            int members = rabbits.first + 1;
            result += ceil(rabbits.second / members) * members;
        }

        return result;
    }
};