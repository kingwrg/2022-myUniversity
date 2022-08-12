#include <string>
#include <vector>
#include <iostream>

using namespace std;
  
class SquareOfDigits
{
  public:
  int getMax(vector<string> data)
  {
    int result = 1;
    int m = data.size();
    int n = data.at(0).length();

    for (int r = 0; r < m; r++) {
        string temp = data.at(r);
        for (int c1 = 0; c1 < n; c1++) {
            for (int c2 = n-1; c2 > c1; c2--) {
                if (temp.at(c1) != temp.at(c2)) continue;

                int w = c2 - c1;

                if ((w+1)*(w+1) < result) continue;

                if ((r+w) < m && temp.at(c1) == data.at(r+w).at(c1) && data.at(r+w).at(c1) == data.at(r+w).at(c2)) {
                    result = (w+1)*(w+1);
                }
            }
        }
    }

    return result;  // return your result
  }
};