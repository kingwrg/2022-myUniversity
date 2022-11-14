#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class NiceOrUgly
{
    public:
    set<char> vowels = {'A', 'E', 'I', 'O', 'U'};
    string describe(string s)
    {
        s = convert(s);

        bool nice = isNice(s);
        bool ugly = isUgly(s);

		if (nice && ugly) {
			return "42";
		}
		else if (nice) {
			return "NICE";
		}
        return "UGLY";
    }

    string convert(string s) 
    {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '?') continue;
            else if (vowels.count(s[i])) {
                s[i] = 'V';
            } else s[i] = 'C';
        }

        return s;
    }

    bool isNice(string s) 
    {
        int c = 0;
        int v = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'C') {
                c++;
                v = 0;
            } else if (s[i] == 'V') {
                v++;
                c = 0;
            } else if (s[i] == '?') {
                if (c == 4) {
                    c = 0;
                    v = 1;
                } else if (v == 2) {
                    c = 1;
                    v = 0;
                } else {
                    c = 0;
                    v = 0;
                }
            }

            if (c >= 5 || v >= 3) return false;
        }

        
        return true;
    }

    bool isUgly(string s) 
    {
        int max_c = 0;
        int max_v = 0;

        for (int i = 0; i < s.length(); i++) {
           if (s[i] == 'C') {
                max_c++;
                max_v = 0;
            } else if (s[i] == 'V') {
                max_v++;
                max_c = 0;
            } else if (s[i] == '?') {
                max_c++;
                max_v++;
            }


            if (max_c >= 5 || max_v >= 3) return true;
        }

        return false;
    }
};