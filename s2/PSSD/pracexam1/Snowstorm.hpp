#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Snowstorm
{
    public:
    int blockedLength(vector<int> startP, vector<int> endP)
    {
        vector<int> road;
        for (int i = 0; i <= 10000; i++) {
            road.push_back(0);
        }

        int n = startP.size();
        for (int i = 0; i < n; i++) {
            for (int j = startP.at(i); j < endP.at(i); j++) {
                road.at(j)++;
            }
        }

        int result = 0;
        for (int i = 0; i < road.size(); i++) {
            if (road.at(i) != 0) result++;
        }
        return result;
    }

};
