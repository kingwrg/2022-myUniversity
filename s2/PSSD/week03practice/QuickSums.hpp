#include <string>
#include <iostream>

using namespace std;

class QuickSums
{
    public:
    int minSums(string numbers, int sum)
    {
        int result = generateSum(numbers, sum, 0, 1);

        if (result == 10) return -1;

        return result;
    }

    int generateSum(string equation, int sum, int sign, int pos) {
        if (stringSum(equation) == sum) 
            return sign;

        if (pos >= equation.length() || stringSum(equation) < sum) 
            return 10;

        string temp = equation.substr(0, pos) + "+" + equation.substr(pos);

        int add = generateSum(temp, sum, sign+1, pos+2);
        int no_add = generateSum(equation, sum, sign, pos+1);

        if (add < no_add) 
            return add;
        return no_add;
    }

    int stringSum(string equation)
    {
        int result = 0;
        int n = equation.length();
        
        int temp = 0;
        for (int i = 0; i < n; i++) 
        {
            if (temp == 0 && equation.at(i) == '0') continue;
            if (equation.at(i) == '+') 
            {
                result += temp;
                temp = 0;
            } else {
                temp = temp * 10 + (equation.at(i) - '0');
            }
        }
        result += temp;
        return result;
    }
};
#include<iostream>
#include<vector>
#include<string>
#define oo 1000000
using namespace std;
 
class QuickSums {
 
public:
    int minSums(string numbers,int sum) {
        int V[10][10][101];
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                for(int k=0;k<101;k++)
                    V[i][j][k]=100000;
        int N = numbers.size();
        for(int q=0;q<N;q++) {
        for(int i=0;i<N-q;i++) {
            string st = numbers.substr(i,q+1); 
            if(atoi(st.c_str())<101)
            V[i][i+q][atoi(st.c_str())] = 0;} }
        for(int l=1;l<N;l++) {
            for(int i=0;i<N-l;i++) {
                int j=i+l;
                for(int k=i;k<j;k++)
                    for(int q1=0;q1<100;q1++)
                        for(int q2=0;q2+q1<=100;q2++)
                            if(V[i][k][q1]<100000 && V[k+1][j][q2] < 100000)
                                V[i][j][q1+q2]=min(V[i][j][q1+q2],V[i][k][q1]+V[k+1][j][q2]+1);}}
        if(V[0][N-1][sum]<100000)
        return V[0][N-1][sum];
        return -1;
    }
};

#include <iostream>
#include <string>
using namespace std;

class QuickSums
{
private:
    int res;

public:
    int minSums(string numbers, int sum)
    {
        res = 20;
        helper(numbers, sum, 0, 0);
        if (res != 20)
        {
            return res;
        }
        else {
            return -1;
        }
    }

    void helper(string curNum, int target, int curSum, int ope)
    {
        if (curNum.length() == 0)
        {
            if (curSum == target)
            {
                res = min(res, ope-1);
            }
            
            return;
        }
        int i = 0;
        int n = curNum.length();
        string newNum;
        while ((i < n) && (stoi(curNum.substr(0, i + 1)) + curSum <= target))
        {
            newNum = curNum.substr(i+1, n-i-1);
            helper(newNum, target, curSum + stoi(curNum.substr(0, i + 1)), ope+1);
            i++;
        }
        return;
    }
};