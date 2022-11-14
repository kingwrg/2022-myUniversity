// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;


// class MonstersValley2
// {
// public:
//     int minimumPrice(vector<int> dread, vector<int> price)
//     { 
//         return minimumPriceHelper(dread, price, 0, 0, 0);
//     }

//     int minimumPriceHelper(vector<int> dread, vector<int> price, int pos, long t_dread, int t_price)
//     {
//         if (pos >= dread.size()) return t_price;

//         if (t_dread < dread[pos]) {
//             t_dread += dread[pos];
//             t_price += price[pos];
//             return minimumPriceHelper(dread, price, pos+1, t_dread, t_price);
//         } 

//         return min(minimumPriceHelper(dread, price, pos+1, t_dread, t_price), minimumPriceHelper(dread, price, pos+1, t_dread + dread[pos], t_price + price[pos]));
//     }
// };

// #include <iostream>
// #include <string>
// #include <string.h>
// #include <vector>

// using namespace std;

// class MonstersValley2{
//     public:
//     long long dp[30][50];
//     long long Max(long long a, long long b)
//     {
//         if (a > b) return a;
//         return b;
//     }
//     int minimumPrice(vector<int> dread, vector<int> price){
//         int n, MaxP, i, j;
//         n = dread.size();
//         MaxP = 2 * n;
//         memset(dp, 0, sizeof(dp));

//         for (i = price[0]; i <= MaxP; i++) dp[0][i] = (long long) dread[0];

//         for (i = 1; i < n; i++)
//             for (j = 1; j <= MaxP; j++) {
//                 if (j > price[i] && dp[i-1][j-price[i]] > 0)
//                     dp[i][j] = dp[i-1][j-price[i]] + (long long) dread[i];
                
//                 if ((long long) dread[i] <= dp[i-1][j]) dp[i][j] = Max(dp[i-1][j], dp[i][j]);

//                 if (j > 1) dp[i][j] = Max(dp[i][j-1], dp[i][j]);
//             }

//         for (i = 0; i < n; i++) {
//             for (j = 1; j <= MaxP; j++)
//                 cout << dp[i][j] << " ";
//             cout << endl;
//         }

//         i = 1;
//         while(dp[n-1][i] == 0) i++;
//         return i;
//     }
// };

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
ll pricepower[30][50];

class MonstersValley2 {
    public:
    int minimumPrice(vector<int> dread, vector<int> price) {
        int dsz = dread.size();
        pricepower[0][price[0]] = dread[0];
        for (int i = 1; i < dsz; i++) {
            for (int j = 45; j >= -1; j--) {
                if (pricepower[i-1][j] >= dread[i]) {
                    pricepower[i][j] = pricepower[i-1][j];
                }
            }

            for (int j = 45; j >= -1; j--) {
                if (pricepower[i-1][j] != 0) {
                    pricepower[i][j+price[i]] = max(pricepower[i][j+price[i]], pricepower[i-1][j]+dread[i]);
                }
            }
        }

        int res = 0;
        for (int i = 0; i< 45; i++) {
            if (pricepower[dsz-1][i] != 0) {
                res = i;
                break;
            }
        }

        for (int i = 0; i < dsz; i++) {
            for (int j = 0; j < 50; j++) {
                cout << pricepower[i][j] << " ";
            }
            cout << endl;
        }

        return res;
    }
};