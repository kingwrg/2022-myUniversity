#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <cstring>

using namespace std;

class JumpyNum
{
    public:
    int dp[11][10];

    int howMany(int low, int high)
    {
        initialDP();

        return countJumpy(high+1) - countJumpy(low);        
    }

    void initialDP() {
        memset(dp, 0, sizeof(dp));

        for (int d = 0; d < 10; d++) {
            dp[1][d] = 1;
        }

        for (int n = 2; n <= 10; n++) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (abs(i-j) >= 2){
                        dp[n][i] += dp[n-1][j];
                    }
                }
            }
        }
    }

    int countJumpy(int numb) 
    {
        string s = to_string(numb);
        int max_len = s.length();
        

        int result = 0;
        for (int i = 1; i < max_len; i++) {
            for (int d = 1; d < 10; d++) {
                result += dp[i][d];
            }
        }


        for (int i = 0; i < max_len; i++) {
            for (int d = 0; d < int(s[i] - '0'); d++) {
                if (i == 0 && d == 0) continue;

                if (i > 0 && abs(int(s[i-1] - '0') - d) < 2) continue;

                result += dp[max_len - i][d];
            }

            if(i > 0 && abs(s[i-1]-s[i]) < 2)
                break;
        }

        return result;
    }
};