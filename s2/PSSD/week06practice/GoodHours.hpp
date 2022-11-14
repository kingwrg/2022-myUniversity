#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

class GoodHours
{
    public:
    int howMany(string beforeTime, string afterTime)
    {
        int bhour = stoi(beforeTime.substr(0,2));
        int bminute = stoi(beforeTime.substr(3,2));

        int ahour = stoi(afterTime.substr(0,2));
        int aminute = stoi(afterTime.substr(3,2));

        int result = 0;
        while (bhour != ahour || bminute != aminute) {
            string time = timeToString(bhour) + timeToString(bminute);

            if (isGood(time)) 
                result++;

            bminute++;
            if (bminute == 60) {
                bminute = 0;
                bhour++;
            }
            if (bhour == 24) 
                bhour = 0;
        }

        result += isGood(afterTime.substr(0,2) + afterTime.substr(3,2));

        return result;
    }

    string timeToString(int t) 
    {
        string zero = "";
        if (t < 10) zero += "0";
        return zero + to_string(t);
    }

    int multiplyString(string s) 
    {
        int result = 1;
        for (int i = 0; i < s.length(); i++) {
            result *= (s[i] - '0');
        }
        return result;
    }

    bool isGood(string t) 
    {
        int a, b;
        for (int i = 1; i <= 3; i++) {
            a = multiplyString(t.substr(0, i));
            b = multiplyString(t.substr(i, 4-i));

            if (a == b) 
                return true;
        }

        return false;
    }
};