#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

class ShipBoxes
{
    public:
    int bestCost(vector<int> box1, vector<int> box2)
    {
        sort(box1.begin(), box1.end());
        sort(box2.begin(), box2.end());

        int result = INT_MAX;
        do {
            do {
                int s1 = max(box1[2], box2[2]);
                int s2 = max(box1[1], box2[1]);
                int s3 = box1[0] + box2[0];
                
                int a = s1*s2;
                int b = s2*s3;
                int c = s3*s1;

                int temp = a + b + c + min(min(a,b),c);
                temp *= 2;

                result = min(result, temp);
            } while (next_permutation(box1.begin(), box1.end()));
        } while (next_permutation(box2.begin(), box2.end()));

        return result;
    }
};