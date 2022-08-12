#include <vector>
#include <iostream>

using namespace std;

class DerivativeSequence
{
    public:
    vector<int> derSeq(vector<int> a, int n)
    {
        if (n == 0) return a;
        int len = a.size();

        for (int i = 0; i < n; i++) 
        {
            len--;
            for (int j = 0; j < len; j++) 
            {
                a.at(j) = a.at(j+1) - a.at(j);
            }
        }

        vector<int> result(a.begin(), a.end()-n);
        return result;
    }

};