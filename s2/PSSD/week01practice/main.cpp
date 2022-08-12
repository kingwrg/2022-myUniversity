#include <iostream>
#include <string>
#include <vector>
#include "PartySeats.hpp"

using namespace std;

int main() {
    PartySeats test;
    vector<string> temp = {"AM girl", "ROB boy", "JIM boy", "AM girl", "DAVE boy", "JO girl"};
    vector<string> res = test.seating(temp);
    for (int i = 0; i < res.size(); i++) {
        cout << res.at(i) << " ";
    }
    cout << endl;
}
