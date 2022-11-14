#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int makeEqualLength(string &a, string &b)
{
    int len1 = a.size();
    int len2 = b.size();
    string add_on = "";
    int diff;
    diff = abs(len1 - len2);

    for (int i = 0; i < diff; i++) {
        add_on += "0";
    }

    if (len1 < len2) {
        a = add_on + a;
    } else if (len1 > len2){
        b = add_on + b; 
    }
    
    return max(len1, len2); 
}

string SMAdd(string a, string b, int base) 
{
    string result = "";
    
    int n = makeEqualLength(a, b);

    int s, c = 0;
    for (int i = n - 1; i >=0; i--) {
        s = c + (a[i] - '0') + (b[i] - '0');
        
        c = s / base;
        s = s % base;

        result = (char)(s + '0') + result;
    }

    if (c > 0) {
        result = (char)(c + '0') + result;
    }

    return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

string SMSubtract(string a, string b, int base) 
{
    string result = "";
    
    int n = makeEqualLength(a, b);

    for (int i = n - 1; i >=0; i--) {
        int diff = (a[i] - '0') - (b[i] - '0');

        if (diff >= 0) {
            result = to_string(diff) + result;
        } else {
            int j = i - 1;
            while (j >= 0) {
                a[j] = ((a[j] - '0') - 1) % base + '0';
                if (a[j] != (char)(base - 1)) {
                    break;
                } else {
                    j--;
                }
            }
            result = to_string(diff + base) + result;
        }
    }

    return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

string Karatsuba(string a, string b, int base) 
{
    int n = makeEqualLength(a, b);

    if (n == 1) {
        if (a == "0" || b == "0") return "0";
        int times = a[0] - '0';
        string temp = b;
        for (int i = 1; i < times; i++) {
            temp = SMAdd(b, temp, base);
        }
        return temp;
    }

    string a0 = a.substr(0, n/2);
    string a1 = a.substr(n/2, n-n/2);
    string b0 = b.substr(0, n/2);
    string b1 = b.substr(n/2, n-n/2);
    
    string p0 = Karatsuba(a0, b0, base);
    string p1 = Karatsuba(a1, b1, base);
    string p2 = Karatsuba(SMAdd(a0, a1, base), SMAdd(b0, b1, base), base);
    string p3 = SMSubtract(p2, SMAdd(p0, p1, base), base);

    for (int i = 0; i < 2*(n-n/2); i++) {
        p0.append("0");
    }
    for (int i = 0; i < n-n/2; i++) {
        p3.append("0");
    }
        
    string result = SMAdd(SMAdd(p0, p1, base), p3, base);

    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

int main()
{
    string test;
    getline(cin, test);
    string I1 = test.substr(0, test.find_first_of(" "));
    string I2 = test.substr(test.find_first_of(" ")+1, test.find_last_of(" ") - test.find_first_of(" ") - 1);
    string B = test.substr(test.find_last_of(" ")+1, test.size() - test.find_last_of(" "));
    int base = stoi(B);
    cout << SMAdd(I1, I2, base) << " " << Karatsuba(I1, I2, base) << " " << 0 <<endl;
}
