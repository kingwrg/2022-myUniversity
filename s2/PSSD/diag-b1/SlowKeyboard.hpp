#include <string>
#include <set>
#include <iostream>

using namespace std;

// I am going to type out what I am trying to do
// This problem is not simple, I still dont quite get it
// From my understanding, we need to figure out the upcoming time
// So that it is minimum to open the door
// It does not matter how far the number is, as long as we move, then it is 2 sec
// If stay the same, then only 1 sec
// This will be the foundation
// We want to stay at one place at long as possible
// And when we done typing, the time we enter will be the same with the current time
// We do not actually need to calculate the time end
// We only need to get the smallest enter time
// Okay I am actually stuck, I dont know what to do
// The fastest time we can get is 4
// Okay, I need to separate min and sec into number
// 4 second is the minimum, so I add 4 sec first, we will get the time
// it takes to enter 4 numbers
// Next we check to see how many digit is the same

class SlowKeyboard
{
    public:
    int enterTime(string time) 
    {
        int result = 4;
        int minute = 0;
        int second = 0;

        set<int> digit;      

        for (int i = 4; i < 11; i++) {
            minute = (time.at(0) - '0') * 10 + (time.at(1) - '0');
            second = (time.at(3) - '0') * 10 + (time.at(4) - '0');
            second += i;
            if (second >= 60) {
                second %= 60;
                minute += 1;
                if (minute >= 60) {
                    minute %= 60;
                }
            }
            digit.insert(minute/10);
            digit.insert(minute%10);
            digit.insert(second/10);
            digit.insert(second%10);

            if (digit.size() == 1 && i == 4) return 4;  
            if (digit.size() == 2 && i < 9) return i;
            if (digit.size() == 4 && i > 8) return i;  
            
        }
        return 4;
    }
};