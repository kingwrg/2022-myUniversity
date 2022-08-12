#include <string>
#include <vector>
#include <iostream>
#include "BootsExchange.hpp"

using namespace std;

int main() {
    BootsExchange test;
    vector<int> left = {3 ,1 ,4 ,7 ,3 ,1 ,4 ,5 ,1};
    vector<int> right = {2 ,5 ,2 ,3 ,4 ,1 ,4 ,6 ,8};
    cout << test.leastAmount(left, right) << endl;
}