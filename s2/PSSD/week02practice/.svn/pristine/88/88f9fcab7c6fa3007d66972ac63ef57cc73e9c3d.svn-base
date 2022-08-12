#include <vector>
#include <iostream>

using namespace std;

class FibonacciDiv2
{
    private:
    vector<int> fibonacci = {0, 1, 1};
    public:
    int find(int N)
    {
        if (N == 0 || N == 1) return 0;

        int f1 = 0;
        int f2 = 0;

        int i = 0;
        int first_len = fibonacci.size();
        while (i < first_len) {
            if (fibonacci.at(i) > N) break;
            i++;
        }

        if (i < first_len) {
            f1 = fibonacci.at(i);
            f2 = fibonacci.at(i-1);
            return compare(N, f1, f2);
        }

        int len = 4;
        while (fibonacci.back() <= N) {
            fib(len);
            len++;
        }

        int second_len = fibonacci.size();
        f1 = fibonacci.at(second_len-1);
        f2 = fibonacci.at(second_len-2);

        return compare(N, f1, f2);
    }

    int compare(int N, int f1, int f2) {
        if (f2 == N) return 0;
        if (N - f2 >= f1 - N)
        {
            return f1 - N;
        }

        return N - f2;
    }

    void fib(int n)
    {
        int len = fibonacci.size();
        while (fibonacci.size() < n) 
        {
            int temp = fibonacci.at(len-1) + fibonacci.at(len-2);
            fibonacci.push_back(temp);
        }
        return;
    }
};