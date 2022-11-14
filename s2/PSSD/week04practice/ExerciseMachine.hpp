#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;

class ExerciseMachine
{
    public:
    int getPercentages(string time)
    {
        int hour = stoi(time.substr(0,2)) * 3600;
        int minute = stoi(time.substr(3,2)) * 60;
        int second = stoi(time.substr(6,2)) + hour + minute;

        int count = 0;
        for (int i = 1; i <= second; i++) {
            if ((i*100)%second == 0 && (i*100)/second != 100) {
                count++;
            }
        }
        return count;
    }
};