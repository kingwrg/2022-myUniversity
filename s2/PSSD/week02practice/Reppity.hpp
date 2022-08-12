#include <string>
#include <iostream>

using namespace std;

class Reppity
{
    public:
    int longestRep(string input)
    {
        int n = input.length();

        for(int len = n; len > 0; len--) 
        {   
            for (int start = 0; start < n - len; start++)
            {
                string temp1 = input.substr(start, len);
                for (int next = start + len; next <= n - len; next++) 
                {
                    string temp2 = input.substr(next, len);
                    if (temp1 == temp2) 
                    {
                        return len;
                    }
                }
            }
        }
        return 0;
    }
};