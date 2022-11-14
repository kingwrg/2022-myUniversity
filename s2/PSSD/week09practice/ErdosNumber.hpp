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

class ErdosNumber
{
    public:
    vector<string> split(string s)
    {
        int pos = 0;
        vector<string> result;
            
        while ((pos=s.find(" ")) != string::npos) {
            string a = s.substr(0, pos);
            result.push_back(a);
            s.erase(0, pos+1);
        }
        result.push_back(s);

        return result;
    }

    vector<string> calculateNumbers(vector<string> publications)
    {
        map<string, int> authors;
        for (auto const& p : publications) {
            vector<string> list = split(p);
            
            for (int i = 0; i < list.size(); i++) {
                string a = list[i];
                if (authors.count(a) > 0) continue;

                int val = (a == "ERDOS") ? 0 : INT_MAX;
                authors.insert(pair<string, int> (a, val));
            }
        }

        map<string, int> index;
        map<string,int>::iterator it;
        int ind = 0;
        for (it = authors.begin(); it != authors.end(); it++, ind++) {
            index.insert(pair<string, int> (it->first, ind));
        }

        vector<vector<string>> graph (authors.size(), vector<string> ());
        for (auto const& p : publications) {
            vector<string> list = split(p);
            
            for (int i = 0; i < list.size(); i++) {
                string a = list[i];
                for (int j = 0; j < list.size(); j++) {
                    if (i==j) continue;
                    graph[index[a]].push_back(list[j]);
                }
            }
        }

        queue<string> q;
        q.push("ERDOS");
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            
            int numb = authors[curr];
            int ind = index[curr];

            for (int i = 0; i < graph[ind].size(); i++) {
                string a = graph[ind][i];
                if (authors[a] != INT_MAX) continue;

                authors[a] = numb + 1;
                q.push(a);
            }
        }

        vector<string> result;
        for (auto const& x : authors) {
            string temp = x.first;
            if (x.second != INT_MAX) temp += ' ' + to_string(x.second);
            result.push_back(temp);
        }

        sort(result.begin(), result.end());
        return result;
    }
};