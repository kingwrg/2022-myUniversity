#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class DownloadingFiles
{
    public:
    double actualTime(vector<string> tasks)
    {
        int n = tasks.size();
        vector<pair<double, double>> files;
        double total_size = 0;
        double total_speed = 0;

        for (int i = 0; i < n; i++) {
            int speed = 0, time = 0;
            sscanf(tasks[i].c_str(), "%d %d", &speed, &time);
            files.push_back(make_pair(speed, time));
        }

        for (int i = 0; i < n; i++)
        {
            double speed = files.at(i).first;
            double time = files.at(i).second;
            total_speed += speed;
            total_size += speed * time;
        }

        return total_size/total_speed;
    }
};