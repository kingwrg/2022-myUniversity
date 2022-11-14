#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class UF
{
    int n;
    vector<int> parent;

public:
    UF(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return find(parent[x]);
    }

    void Union(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px != py)
        {
            parent[px] = py;
        }
    }
};

vector<string> seperate(string s, char delimiter)
{
    istringstream ss(s);

    string word;

    vector<string> arr;

    // print the substrings separated by delimiter 1-by-1
    while (getline(ss, word, delimiter))
    {

        arr.push_back(word);
    }
    return arr;
}

vector<vector<int>> convert_to_cost(vector<string> s)
{
    vector<vector<int>> res;
    for (int i = 0; i < s.size(); i++)
    {
        vector<int> tmp;
        for (int j = 0; j < s[i].length(); j++)
        {
            int num = s[i][j] - 'A';
            if (num > 25)
            {
                num -= 6;
            }
            tmp.push_back(num);
        }
        res.push_back(tmp);
    }
    return res;
}

int main()
{
    string example = "";

    getline(cin, example);

    vector<string> input = seperate(example, ' ');

    vector<string> country = seperate(input[0], ',');
    vector<string> build_s = seperate(input[1], ',');
    vector<string> destroy_s = seperate(input[2], ',');

    vector<vector<int>> build = convert_to_cost(build_s);
    vector<vector<int>> destroy = convert_to_cost(destroy_s);

    int n = country.size();
    UF graph(n);

    vector<vector<int>> build_edges;
    vector<vector<int>> destroy_edges;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            build_edges.push_back({i, j, build[i][j]});
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (country[i][j] == '1')
            {
                destroy_edges.push_back({i, j, destroy[i][j]});
            }
        }
    }

    sort(build_edges.begin(), build_edges.end(), [](vector<int> a, vector<int> b)
         { return a[2] < b[2]; });
    sort(destroy_edges.begin(), destroy_edges.end(), [](vector<int> a, vector<int> b)
         { return a[2] > b[2]; });

    int res = 0;

    for (int i = 0; i < destroy_edges.size(); i++)
    {
        int x = destroy_edges[i][0];
        int y = destroy_edges[i][1];
        int cost = destroy_edges[i][2];
        int px = graph.find(x);
        int py = graph.find(y);

        if (px == py)
        {
            res += cost;
        }
        else
        {
            graph.Union(x, y);
        }
    }

    for (int i = 0; i < build_edges.size(); i++)
    {
        int x = build_edges[i][0];
        int y = build_edges[i][1];
        int cost = build_edges[i][2];
        int px = graph.find(x);
        int py = graph.find(y);

        if (px != py)
        {
            res += cost;
            graph.Union(x, y);
        }
    }
    cout << res << endl;
    return 0;
}