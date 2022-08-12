#include <string>
#include <iostream>

using namespace std;

class BlackAndRed
{
    public:
    int cut(string deck)
    {
        int n = deck.length();
        string temp = deck;

        for (int pos = 1; pos <= n; pos++) 
        {
            // cout << pos << " " << countRB(temp) << " " << temp << endl; 
            if (countRB(temp)) return pos-1;
            temp = deck.substr(pos, n-pos) + deck.substr(0, pos);
        }

        return 0;
    }

    bool countRB(string deck) 
    {
        int n = deck.length();
        int red = 0;
        int black = 0;

        for (int i = 0; i < n; i++) 
        {
            if (deck.at(i) == 'R') red++;
            else black++;

            if (red > black) return false;
        }

        return true;
    }
};