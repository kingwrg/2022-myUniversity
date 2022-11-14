#include <iostream>
#include <string>
#include <vector>
#include "MonstersValley2.hpp"

using namespace std;

int main()
{
    MonstersValley2 test;
    vector<int> temp1 = {200, 107, 105, 206, 307, 400};
    vector<int> temp2 = {1, 2, 1, 1, 1, 2};
    cout << test.minimumPrice(temp1, temp2) << endl;
}