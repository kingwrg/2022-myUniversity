#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class MatchNumbersEasy
{
    public:
    string maxNumber(vector<int> matches, int n)
    {
        vector<vector<int>> order (matches.size(), vector<int> (2, 0));
        sortCost(matches, order);

        string result = "";
        int first = 0;
        for (int i = 0; i < order.size(); i++) {
            if (order[i][0] == 0) continue;
            n -= order[i][1];
            first = order[i][1] - order[0][1];
            result += to_string(order[i][0]);
            break;
        }
        while (n > 0) {
            if (n >= order[0][1]) {
                n -= order[0][1];
                result += to_string(order[0][0]);
            } else break;
        }

        n += first;
        for (int i = 0; i < result.length(); i++) {
            int digit = 0;
            for (int j = matches.size() - 1; j >= 0; j--) {
                if (n >= matches[j]) {
                    n -= matches[j];
                    digit = j;
                    break;
                }
            }

            result[i] = digit + '0';
        }

        return result;
    }

    void sortCost(vector<int> &matches, vector<vector<int>> &order) 
    {
        for (int i = 0; i < matches.size(); i++) {
            order[i][0] = i;
            order[i][1] = matches[i];
        }

        sort(order.begin(), order.end(), [] 
            (const vector<int> &a, const vector<int> &b) {
                if (a[1] == b[1]) return a[0] > b[1];
                return a[1] < b[1];
            });

        for (int i = 0; i < matches.size(); i++) {
            matches[i] -= order[0][1];
        }
    }
};

    // string maxNumber(vector <int> matches, int n) {
    //     string dp[51];
    //     int n1 = matches.size();
    //     for (int i = 0; i < n1; ++i) {
    //         dp[matches[i]] = char(i + '0');
    //     }
        
    //     for (int i = 2; i <= n; ++i) {
    //         for (int j = 1; j <= i / 2; ++j) {
    //             string temp = dp[j] + dp[i - j];
    //             sort(temp.begin(), temp.end());
    //             reverse(temp.begin(), temp.end());
    //             if ((temp.size() > dp[i].size() && temp[0] != '0') || (temp.size() == dp[i].size() && temp > dp[i])) {
    //                 dp[i] = temp;
    //             }
    //         }
    //     }
        
    //     string res = dp[n];
        
    //     if (count(res.begin(), res.end(), '0') == res.size()) return "0";
    //     else return res;
    // }