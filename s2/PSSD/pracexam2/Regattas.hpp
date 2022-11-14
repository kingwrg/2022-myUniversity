#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Regattas 
{
    public:
    int betResult (vector<string> regattas, string ticket) 
    {
        set<char> all_boats;
        set<char> win;
        for (int i = 0; i < regattas.size(); i++) {
            win.insert(regattas[i][0]);
            for (int j = 0; j < regattas[i].length(); j++) {
                all_boats.insert(regattas[i][j]);
            }
        }
        set<char> boat;
        for (int i = 0; i < regattas.size(); i++) {
            boat.clear();
            for (int j = 0; j < regattas[i].length(); j++) {
                boat.insert(regattas[i][j]);
            }

            int count = 0;
            for (int k = 0; k < ticket.length(); k++) {
                if (boat.count(ticket[k]) != 0) count++;
            }
            if (count > 1) return -1;
        }

        set<char> bets;
        int result = 0;
        for (int i = 0; i < ticket.length(); i++) {
            if (bets.count(ticket[i]) != 0) return -1;

            if (all_boats.count(ticket[i]) == 0) return -1;

            if (win.count(ticket[i]) != 0) result++;

            bets.insert(ticket[i]);
        }

        return result;
    }
};