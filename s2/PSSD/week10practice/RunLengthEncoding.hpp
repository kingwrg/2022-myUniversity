#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

class RunLengthEncoding
{
    public:
    string decode(string text)
    {
        int cap = 50;
        int numb = 0;
        string result = "";

        for (int i = 0; i < text.length(); i++) {
            if (isdigit(text[i])) {
                numb = numb*10 + (text[i] - '0');
                if (numb > cap) return "TOO LONG"; 
            } else {
                if (numb == 0) numb = 1;
                if (numb > cap) return "TOO LONG"; 
                string temp = string(numb, text[i]);
                result += temp;
                cap -= numb;
                numb = 0;
            }
        }

        return result;
    }
};