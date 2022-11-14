#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// add two numbers
string add(string a, string b, int base)
{
    int len_a, len_b;

    len_a = a.size();
    len_b = b.size();

    string s = "";
    string sum = "";

    int diff;
    diff = abs(len_a - len_b);

    // Padding 0 in front of the
    // number to make both numbers equal
    for (int i = 0; i < diff; i++)
        s += "0";

    // Condition to check if the strings
    // have lengths mis-match
    if (len_a < len_b)
    {
        a = s + a;
    }
    else
    {
        b = s + b;
    }

    int cur, carry = 0;

    // Loop to find the find the sum
    // of two integers of base
    int max_len = max(len_a, len_b);
    for (int i = max_len - 1; i >= 0; i--)
    {
        // add a[i]+b[i]+carry
        cur = (a[i] - '0') + (b[i] - '0') + carry;

        // update carry
        carry = cur / base;

        // get current digit
        cur = cur % base;

        // Update sum result
        sum = (char)(cur + '0') + sum;
    }

    if (carry > 0)
    {
        sum = (char)(carry + '0') + sum;
    }
    // clear leading zero
    return sum.erase(0, min(sum.find_first_not_of('0'), sum.size() - 1));
}

// subtract two numbers

string subtract(string a, string b, int base)
{
    int len_a = a.size();
    int len_b = b.size();

    string s = "";
    string result = "";
    int diff;
    diff = abs(len_a - len_b);

    // Padding 0 in front of the
    // number to make both numbers equal
    for (int i = 0; i < diff; i++)
        s += "0";

    // Condition to check if the strings
    // have lengths mis-match
    if (len_a < len_b)
    {
        a = s + a;
    }
    else
    {
        b = s + b;
    }

    int max_len = max(len_a, len_b);

    for (int i = max_len - 1; i >= 0; i--)
    {
        diff = (a[i] - '0') - (b[i] - '0');

        if (diff >= 0)
        {
            result = to_string(diff) + result;
        }
        else
        {
            int j = i - 1;
            while (j >= 0)
            {
                a[j] = ((a[j] - '0') - 1) % base + '0';
                if (a[j] != (char)(base - 1))
                {
                    break;
                }
                else
                {
                    j--;
                }
            }

            result = to_string(diff + base) + result;
        }
    }
    return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

// calculate partial multipication for school method multiplication
string partial_multiply(string a, string b, int base)
{
    int len_a, len_b;

    len_a = a.size();
    len_b = b.size();

    string s = "";
    string result = "";

    int diff;
    diff = abs(len_a - len_b);

    // Padding 0 in front of the
    // number to make both numbers equal
    for (int i = 0; i < diff; i++)
        s += "0";

    // Condition to check if the strings
    // have lengths mis-match
    if (len_a < len_b)
    {
        a = s + a;
    }
    else
    {
        b = s + b;
    }

    int cur, carry = 0;

    // 2 loops to find the find the partial multiplication result
    int max_len = max(len_a, len_b);
    string partial = "";
    for (int i = max_len - 1; i >= 0; i--)
    {
        partial = "";
        carry = 0;
        for (int j = max_len - 1; j >= 0; j--)
        {
            cur = (a[j] - '0') * (b[i] - '0') + carry;
            // update carry
            carry = cur / base;

            // get current digit
            cur = cur % base;

            // Update partial result
            partial = (char)(cur + '0') + partial;
        }

        if (carry > 0)
        {
            partial = (char)(carry + '0') + partial;
        }

        // update result
        if (result != "")
        {
            for (int k = 1; k < max_len - i; k++)
            {
                partial += '0';
            }

            result = add(result, partial, base);
        }
        else
        {
            result = partial;
        }
    }
    // clear leading zero
    return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

// school multiplication method (for n < 4)
string school_multiply(string a, string b, int base)
{
    int len_a = a.size();
    int len_b = b.size();
    int max_len = max(len_a, len_b);
    string s = "";
    int diff;
    diff = abs(len_a - len_b);

    // Padding 0 in front of the
    // number to make both numbers equal
    for (int i = 0; i < diff; i++)
        s += "0";

    // Condition to check if the strings
    // have lengths mis-match
    if (len_a < len_b)
    {
        a = s + a;
    }
    else
    {
        b = s + b;
    }

    int k = max_len / 2;

    string a0 = a.substr(0, k);
    string a1 = a.substr(k, max_len - k);
    string b0 = b.substr(0, k);
    string b1 = b.substr(k, max_len - k);

    string p11 = partial_multiply(a1, b1, base);
    string p10 = partial_multiply(a1, b0, base);
    string p01 = partial_multiply(a0, b1, base);
    string p2 = add(p10, p01, base);
    string p00 = partial_multiply(a0, b0, base);

    for (int i = 0; i < 2 * (max_len - k); i++)
    {
        p00 += '0';
    }
    for (int i = 0; i < (max_len - k); i++)
    {
        p2 += '0';
    }

    string result = add(add(p11, p2, base), p00, base);
    // clear leading zero
    return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

// karatsuba multiplication method
string multiply(string a, string b, int base)
{
    int len_a = a.size();
    int len_b = b.size();
    int max_len = max(len_a, len_b);
    string s = "";
    int diff;
    diff = abs(len_a - len_b);

    // Padding 0 in front of the
    // number to make both numbers equal
    for (int i = 0; i < diff; i++)
        s += "0";

    // Condition to check if the strings
    // have lengths mis-match
    if (len_a < len_b)
    {
        a = s + a;
    }
    else
    {
        b = s + b;
    }

    if (max_len < 4)
    {
        return school_multiply(a, b, base);
    }

    int k = max_len / 2;

    string a0 = a.substr(0, k);
    string a1 = a.substr(k, max_len - k);
    string b0 = b.substr(0, k);
    string b1 = b.substr(k, max_len - k);

    string p0 = multiply(a0, b0, base);
    string p1 = multiply(a1, b1, base);
    string p2 = multiply(add(a0, a1, base), add(b0, b1, base), base);
    string p3 = subtract(p2, add(p0, p1, base), base);

    for (int i = 0; i < 2 * (max_len - k); i++)
    {
        p0 += '0';
    }
    for (int i = 0; i < (max_len - k); i++)
    {
        p3 += '0';
    }

    string result = add(add(p0, p1, base), p3, base);
    // clear leading zero
    return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

int main()
{
    string example = "";

    getline(cin, example);
    istringstream ss(example);

    string word;

    char delimiter = ' ';

    vector<string> arr;

    // print the substrings separated by delimiter 1-by-1
    while (getline(ss, word, delimiter))
    {

        arr.push_back(word);
    }

    string a = arr.at(0);
    string b = arr.at(1);
    int base = stoi(arr.at(2));

    cout << add(a, b, base) << " " << multiply(a, b, base) << " 0" << endl;
    return 0;
}