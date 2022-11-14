#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class KokoBananas 
{
    public:
    int lastHand(vector<int> hands, int K)
    {
        int max_val = 0;
        int max_pos = 0;
        for (int k = 1; k <= K; k++) {
            for (int i = 0; i < hands.size(); i++) {
                if (hands[i] > max_val) {
                    max_val = hands[i];
                    max_pos = i;
                }
            }
            hands[max_pos]--;
            max_val = 0;
        }

        return max_pos;
    }
};