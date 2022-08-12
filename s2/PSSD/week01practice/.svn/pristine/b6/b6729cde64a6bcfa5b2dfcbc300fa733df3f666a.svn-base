#include <string>
#include <vector>
#include <iostream>

using namespace std;
  
class CircularLine
{
  public:
  int longestTravel(vector<int> t)
  {
    int n = t.size();
    int max = -1;

    for (int i = 0; i < n ; i++) {
        for (int j = i + 1; j < n; j++) {
            int path1 = 0;
            int path2 = 0;

            for (int k = i; k < j; k++) {
              path1 += t.at(k);
            }

            for (int l = j; l < n; l++) {
              path2 += t.at(l);
            }

            for (int m = 0; m < i; m++) {
              path2 += t.at(m);
            }

            if (path1 > path2) path1 = path2;
            if (path1 > max) max = path1;
        }
    }

    return max;  // return your result
  }
};