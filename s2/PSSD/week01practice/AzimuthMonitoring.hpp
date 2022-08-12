#include <string>
#include <vector>
#include <iostream>

using namespace std;
  
class AzimuthMonitoring
{
  public:
  int getAzimuth(vector<string> instructions)
  {
    int n = instructions.size();
    int result = 0;

    for (int i = 0; i < n; i++) {
        string temp = instructions.at(i);

        if (temp.front() == 'H') break;

        else if (temp.front() == 'T') result += 180;

        else if (temp.front() == 'R') {
            if (temp.length() < 6) result += 90;
            else {
                result += stoi(temp.substr(6));
            }
        } 
        
        else if (instructions.at(i).front() == 'L') {
            if (temp.length() < 5) result -= 90;
            else {
                result -= stoi(temp.substr(5));
            }
            if (result < 0) result+=360;
        }

        result%=360;
    }

    return result;  // return your result
  }
};