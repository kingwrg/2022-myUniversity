#include <iostream>
#include <string>
#include <vector>
#include "GoodHours.hpp"

using namespace std;

int main()
{
    GoodHours test;
    cout << test.howMany("23:10","01:23") << endl;
}