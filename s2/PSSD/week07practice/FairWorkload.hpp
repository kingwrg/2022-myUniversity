#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <climits>
#include <bitset>
#include <cmath>

using namespace std;

class FairWorkload
{
    public:
    int getMostWork(vector<int> folders, int workers)
    {
        vector<string> combination = fillBins(folders.size()-1, workers);
        vector<int> max_workload;

        for (int i = 0; i < combination.size(); i++) {
            int sum = 0;
            int max_comb = 0;

            for (int j = 0; j < combination[i].size(); j++) {
                sum += folders[j];
                if (combination[i][j] == '1') {
                    max_comb = max(max_comb, sum);
                    sum = 0;
                }
            }
            sum += folders[folders.size()-1];
            max_comb = max(max_comb, sum);

            max_workload.push_back(max_comb);
        }
        
        return *min_element(max_workload.begin(), max_workload.end());
    }

    vector<string> fillBins(int n, int workers) 
    {
        vector<string> bins;
        for (int i = 0; i < (pow(2,n)); i++) {
            string bin10 = bitset<16>(i).to_string();
            int c_workers = 0;

            for (int i = 0; i < bin10.length(); i++) {
                if (bin10[i] == '1') {
                    c_workers++;
                }
            }

            if (c_workers == (workers-1)) {
                bins.push_back(bin10.substr((bin10.length()-n), bin10.length()));
            }
        }
        return bins;
    }

};