#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>

using namespace std;

class NumberSplit
{
    public:
    vector<int> dp;
    int longestSequence(int start) {
        dp.clear();

        for (int i = 0; i < 100000; i++) {
            dp.push_back(-1);
        }

        return longestSequenceHelper(start);
    }

    int  longestSequenceHelper(int start) {
        if (start < 10) {
            return 1;
        }

        vector<int> possCombs;
        vector<int> result;

        string startStr = to_string(start);
        int startLen = startStr.length();

        possCombs = generateComb(startStr, startLen-1);
        for (int i = 0; i < possCombs.size(); i++) {
            if (dp[possCombs[i]] == -1) {
                int holder = longestSequenceHelper(possCombs[i]) + 1;
                dp[possCombs[i]] = holder;
            }
            result.push_back(dp[possCombs[i]]);
        }

        return *max_element(&result[0], &(result[result.size()]));  
    }

    vector<int> generateComb(string num, int k) {
        vector<string> bins;
        vector<string> eqns;
        vector<int> result;

        int curr = 1;
        string totalStr = "";

        // Generate place to put *
        for (int i = 1; i < (pow(2,k)); i++) {
            string bin10 = bitset<10>(i).to_string();
            bins.push_back(bin10.substr((bin10.length()-k), bin10.length()));
        }

        for (int x = 0; x < bins.size(); x++) {
            for (int y = 0; y < bins[x].length(); y++) {
                totalStr += num[y];
                if (bins[x][y] == '1') {
                    curr = curr * atoi(&totalStr[0]);
                    totalStr = "";
                }
            }

            totalStr += num[num.length()-1];
            curr = curr * atoi(&totalStr[0]);
            result.push_back(curr);

            curr = 1;
            totalStr = "";
        }

        return result;
    }
};