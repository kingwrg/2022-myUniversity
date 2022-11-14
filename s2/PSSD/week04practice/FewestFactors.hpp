#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class FewestFactors
{
    public:
    int number(vector<int> digits)
    {
        vector<int> check;
        int n = digits.size();
        for (int i = 0; i < n; i++)
        {
            check.push_back(0);
        }
        return numberHelper(digits, vector<int> {}, check, 99999, digits.size());
    }

    int numberHelper(vector<int> digits, vector<int> copy, vector<int> check, int min_val, int n)
    {
        if (copy.size() >= n) {
            return createNumb(copy);
        }

        for (int i = 0; i < n; i++) {
            if (check.at(i)) continue;

            vector<int> check_copy(check);
            vector<int> temp(copy);
            temp.push_back(digits.at(i));
            check_copy.at(i) = 1;

            int c = numberHelper(digits, temp, check_copy, min_val, n);

            if (countFactors(c) > countFactors(min_val)) continue;
            else if (countFactors(c) == countFactors(min_val) && c > min_val) continue;
            
            min_val = c;
        }

        return min_val;
    }

    int createNumb(vector<int> digits)
    {
        int result = 0;
        for (int i = 0; i < digits.size(); i++)
        {
            result = result*10 + digits.at(i);
        }
        return result;
    }

    int countFactors(int number)
    {
        set<int> factors;
        for (int i = 1; i <= number; i++)
        {
            if (factors.count(i)) break;
            if (number % i == 0)
            {
                factors.insert(i);
                factors.insert(number/i);
            }
        }
        return factors.size();
    }
};