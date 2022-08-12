#include <iostream>
#include <string>
#include <vector>
#include "DerivativeSequence.hpp"

using namespace std;

int main() {
    DerivativeSequence test;
    vector<int> temp = {-100,100};
    vector<int> result = test.derSeq(temp, 0); 
    for (int i = 0; i < result.size(); i++) 
    {
        cout << result.at(i) << " ";
    }
    cout << endl;
}