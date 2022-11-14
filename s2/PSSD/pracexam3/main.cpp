#include <iostream>
#include <vector>
#include <string>
#include "DinnerLighting.hpp"

using namespace std;

int main()
{
    DinnerLighting test;
    vector<string> temp ={".....",
".O...",
"...O.",
"....."};
    cout << test.countDarkSquares(4,5,temp) << endl;
}