using namespace std;
  
class Inchworm
{
  public:
  int lunchtime(int branch, int rest, int leaf)
  {
    int result = 0;
    int distance = 0;

    while (distance <= branch) {
        if (distance % leaf == 0) result++;
        distance += rest;
    }

    return result;  // return your result
  }
};