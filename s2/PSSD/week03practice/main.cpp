#include <iostream>
#include <string>
#include <vector>
#include "QuickSum.hpp"

using namespace std;

int main()
{
    QuickSum test;
    cout << test.minSums("0123456789", 45) << endl;
}