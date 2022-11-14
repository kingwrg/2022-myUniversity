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

class SentenceDecomposition
{
    public:
    bool isTransformed(string a, string b)
    {
        sort(a.begin(), a.end()); 
        sort(b.begin(), b.end());

        if (a != b) return false;
        return true;
    }

    int calculateCost(string a, string b)
    {
        int result = 0;

        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) result++;
        }

        return result;
    }

    int decompose(string sentence, vector<string> validWords)
    {
        int n = sentence.length();
        vector<int> dp (51, 9999);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                string word = sentence.substr(j, i-j);

                for (int k = 0; k < validWords.size(); k++) {
                    int cost = 9999;
                    if (isTransformed(word, validWords[k])) {
                        cost = calculateCost(word, validWords[k]);
                    }
                    dp[i] = min(dp[i], dp[j] + cost);
                }
            }
        }

        return (dp[n] == 9999) ? -1 : dp[n];
    }
};