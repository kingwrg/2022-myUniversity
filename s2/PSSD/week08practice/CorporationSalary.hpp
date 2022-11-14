#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

class CorporationSalary
{
    public:

    long totalSalary(vector<string> relations)
    {
        vector<vector<int>> managers;
        vector<int> salary (relations.size(), 1);
        vector<int> check (relations.size(), 0);

        manageWho(relations, managers);

        int result = 0;
        for (int i = 0; i < salary.size(); i++) {
            if (!check[i]) calculateSalary(managers, salary, check, i);
            result += salary[i];
        }
        return result;
    }

    void manageWho(vector<string> relations, vector<vector<int>> &managers) 
    {
        for (int i = 0; i < relations.size(); i++) {
            vector<int> person;
            for (int j = 0; j < relations[0].size(); j++) {
                if (relations[i][j] == 'Y') {
                    person.push_back(j);
                } 
            }
            managers.push_back(person);
        }
    }

    void calculateSalary(vector<vector<int>> managers, vector<int> &salary, vector<int> &check, int pos) 
    {
        check[pos] = 1;
        if (managers[pos].size() == 0) return;

        int total = 0;
        for (int i = 0; i < managers[pos].size(); i++) {
            if (!check[managers[pos][i]]) calculateSalary(managers, salary, check, managers[pos][i]);
            total += salary[managers[pos][i]];
        }

        salary[pos] = total;
    }
};