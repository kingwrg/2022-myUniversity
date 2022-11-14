#include <iostream>
#include <vector>
#include <string>
#include "SimpleDuplicateRemover.hpp"

using namespace std;

int main()
{
    SimpleDuplicateRemover test;
    vector<int> temp = {1,5,5,1,6,1};
    vector<int> res = test.process(temp);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}