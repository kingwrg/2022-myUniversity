#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class BootsExchange
{
    public:
    int leastAmount(vector<int> left, vector<int> right)
    {
        int result = 0;
        map<int, int> boots;
        int n = left.size();

        for (int i = 0; i < n; i++) {
            int l = left.at(i);

            if (boots.count(l)) {
                boots[l]++;
            } else {
                boots.insert(pair<int,int> (l,1));
            }
        }

        for (int i = 0; i < n; i++) {
            int r = right.at(i);

            if (boots.count(r)) {
                if (boots[r] > 0) {
                    boots[r]--;
                }
            }
        }

        for (const auto &item : boots) {
            // cout << item.first << " " << item.second << endl;
            result+=item.second; 
        }

        return result;
    }
};