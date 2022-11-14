#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <climits>
#include <bitset>
#include <cmath>

using namespace std;

class MinimalDifference
{
    public:
    int findNumber(int A, int B, int C)
    {
        int result = A;
        int ds_c = digitSum(C);
        int diff = INT_MAX;
        for (int i = A; i <= B; i++) {
            int temp = digitSum(i);
            if (diff > abs(temp - ds_c)) {
                diff = abs(temp - ds_c);
                result = i;
            }
        }   
        return result;
    }

    int digitSum(int num)
    {
        int result = 0;
        while (num > 0) {
            int d = num % 10;
            result += d;
            num /= 10;
        }
        return result;
    }
};