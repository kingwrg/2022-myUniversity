#include <string>
#include <iostream>

using namespace std;

class QuickSum
{
    public:
    int minSums(string numbers, int sum)
    {
        int n = numbers.length();
        int result = 0;
        string equation = "";

        for (int i = 0; i < n; i++) 
        {   
            equation += numbers.at(i);
            if (i < n-1) equation += '+';
        }

        for (int i = 1; i < equation.length(); i+=2)
        {
            
        }
        cout << equation << endl;
        cout << stringSum(equation) << endl;
        if (stringSum(equation) == sum) return result;
        return -1;
    }

    int stringSum(string equation)
    {
        int result = 0;
        int n = equation.length();

        string temp = "";
        for (int i = 0; i < n; i++) 
        {
            if (equation.at(i) == '+') 
            {
                result += stoi(temp);
                temp = "";
            }
            temp += equation.at(i);
        }
        result += stoi(temp);
        return result;
    }
};