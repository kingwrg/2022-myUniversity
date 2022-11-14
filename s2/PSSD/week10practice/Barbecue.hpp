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

class Barbecue
{
    public:
    bool updateVal(int v1, int e1, int v2, int e2)
    {   
        return (e1 < e2) || (e1 == e2 && v1 < v2);
    }

    int eliminate(int n, vector<int> voter, vector<int> excluded) 
    {
        vector<int> vote_count (n, 0);
        vector<int> exclude_count (n, 0);

        for (int i = 0; i < voter.size(); i++) {
            vote_count[voter[i]]++;
            exclude_count[excluded[i]]++;
        }

        int result = 0;
        int cvote = vote_count[0];
        int cexclude = exclude_count[0];
        for (int i = 1; i < n; i++) {
            if (updateVal(cvote, cexclude, vote_count[i], exclude_count[i])) {
                result = i;
                cvote = vote_count[i];
                cexclude = exclude_count[i];
            }  
        }

        return result;
    }
};