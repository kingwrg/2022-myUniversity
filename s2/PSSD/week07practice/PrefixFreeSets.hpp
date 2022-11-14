#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

class PrefixFreeSets
{
    public:
    int maxElements(vector<string> words)
    {
        // sort(words.begin(), words.end(), []
        //     (const std::string& first, const std::string& second){
        //     return first.size() < second.size();
        // });

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i == j) continue;
                if (isPrefix(words[i], words[j])) {
                    words.erase(words.begin() + i);
                    i--;
                    break;
                }
            }
        }

        return words.size();
    }

    bool isPrefix(string a, string b)
    {
        if (a.length() > b.length()) return false;

        return a == b.substr(0, a.length());
    }
};