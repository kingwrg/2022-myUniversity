#include <iostream>

using namespace std;

class FracCount
{
    public:
    int position(int numerator, int denominator)
    {
        int n = 1;
        int d = 2;
        int result = 1;

        while (d <= denominator)
        {
            if (n == numerator && d == denominator) break;
            
            if (gcd(n, d) == 1) result++;
           
            n++;
            if (n % d == 0) 
            {
                n = 1;
                d++;
            }
        }

        return result;
    }

    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);   
    }
};