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

class DifferentStrings
{
    public:
    int countDiff(string A, string B) 
    {
        int result = 0;
        for (int i = 0; i < A.length(); i++) {
            if (A[i] != B[i]) result++;
        }
        return result;
    }

    int minimize(string A, string B)
    {
        int len_diff = B.length() - A.length();
        int result = A.length();

        for (int i = 0; i <= len_diff; i++) {
            int temp = countDiff(A, B.substr(i, A.length()));
            result = min(temp, result);
        }

        return result;
    }
};