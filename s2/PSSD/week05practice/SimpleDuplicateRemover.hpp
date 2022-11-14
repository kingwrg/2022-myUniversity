#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class SimpleDuplicateRemover
{
    public:
    vector<int> process(vector<int> sequence)
    {
        int n = sequence.size();
        set<int> unique;
        vector<int> result;
        for (int i = n-1; i >=0; i--) {
            if (unique.count(sequence[i])) 
                continue;

            result.insert(result.begin(), sequence[i]);
            unique.insert(sequence[i]);
        }

        return result;
    }
};

