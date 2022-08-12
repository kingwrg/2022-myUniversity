#include <array>
#include <iostream>

using namespace std;  

class ThrowTheBall
{
  public:
  int timesThrown(int N, int M, int L)
  {
    int result = 0;
    array<int, 51> circle;
    circle.fill(0);

    int current = 1;
    while (++circle.at(current) < M) {
        // cout << current << " " << circle.at(current) << endl;
        if (circle.at(current) % 2 == 0) {
            current = (current + L) % N;
        } else {
            current -= L;
        }
        if (current <= 0) current += N;
        result++;
        // cout << current << endl;
        // cout << result << endl;
    }

    return result;  // return your result
  }
};