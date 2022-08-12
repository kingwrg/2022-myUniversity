#include <string>
#include <set>
#include <iostream>

using namespace std;

class HenrysKey
{
    public:
    int howMany(string S)
    {
        set<string> set;
        int n = S.length();
        for (int i = 0; i < n; i++) {
            string temp = S.substr(0,i) + S.substr(i+1, n - i - 1);
            set.insert(temp);
        }
        return set.size(); 
    }
};