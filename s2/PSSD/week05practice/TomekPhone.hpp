#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>

using namespace std;

class TomekPhone
{
    public:
    int minKeystrokes(vector<int> frequencies, vector<int> keySizes)
    {
        int keyLen = 0;
        for (int i = 0; i < keySizes.size(); i++) {
            keyLen += keySizes[i];
        }

        if (keyLen < frequencies.size()) return -1;

        int result = 0;
        int keystroke = 1;
        int count = 0;

        sort(frequencies.rbegin(), frequencies.rend());

        while (keyLen > 0) {
            for (int i = 0; i < keySizes.size(); i++) {
                if (keySizes[i] == 0) continue;
                
                keySizes[i]--;
                keyLen--;

                result += keystroke * frequencies[count];

                count++;
                if (count >= frequencies.size()) return result;
            }

            keystroke++;
        }

        return result;
    }
};