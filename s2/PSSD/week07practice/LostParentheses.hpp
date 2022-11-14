#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

class LostParentheses
{
    public: 
    int minResult(string e)
    {
        int result = 0;
        int num = 0;

        bool check = false;
        for (int i = 0; i < e.length(); i++) {
            if (e[i] == '+' || e[i] == '-') {
                if (check) {
                    result -= num;
                } else {
                    result += num;
                }

                if (!check && e[i] == '-') {
                    check = true;
                }

                num = 0;
            } else {
                num = num*10 + e[i] - '0';
            }
        }
        if (check) result -= num;
        else result += num;

        return result;
    }
};