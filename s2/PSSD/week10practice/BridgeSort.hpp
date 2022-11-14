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

class BridgeSort
{
    public:
    vector<string> separateCards(string hand)
    {
        vector<string> result;
        int n = hand.size();
        for (int i = 0; i < n; i+=2) {
            result.push_back(hand.substr(0,2));
            hand = hand.substr(2);
        }
        return result;
    }

    string sortedHand(string hand)
    {
        vector<string> cards = separateCards(hand);

        sort(cards.begin(), cards.end(), [] (const string& a, const string& b) {
            string suit = "CDHS";
            string val = "23456789TJQKA";

            int a1 = suit.find(a[0]);
            int b1 = suit.find(b[0]);
            if (a1 != b1) return a1 < b1;

            int a2 = val.find(a[1]);
            int b2 = val.find(b[1]);
            return a2 < b2;
        });

        string result = "";
        for (int i = 0; i < cards.size(); i++) {
            result += cards[i];
        }

        return result;
    }
};