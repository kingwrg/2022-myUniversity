#include <iostream>
#include <string>
#include <vector>
#include "DownloadingFiles.hpp"

using namespace std;

int main()
{
    DownloadingFiles test;
    vector<string> temp = {"3 57","2 22"};
    cout << test.actualTime(temp) << endl;
}