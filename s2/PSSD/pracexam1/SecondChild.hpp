#include <string>
#include <vector>
using namespace std;

class SecondChild
{
    public:
    string chooseName(string father, string mother, string child1, string gender)
    {
        string c1_gender = getGender(child1);
        string f_first = father.substr(0, father.find(" "));
        string m_first = mother.substr(0, mother.find(" "));
        string c1_second = child1.substr(child1.find(" "), (child1.length() - child1.find(" ")));
        
        string child2 = "";
        if (c1_gender == gender) {
            if (gender == "Boy") {
                child2 += f_first;
            } else {
                child2 += m_first;
            }
            child2 += c1_second;
        } else {
            if (gender == "Boy") {
                child2 = father.substr(father.find(" ")+1, (father.length() - father.find(" "))) + " " + f_first;
            } else {
                child2 = mother.substr(mother.find(" ")+1, (mother.length() - mother.find(" "))) + " " + m_first;
            }
        }

        return child2;
    }

    string getGender(string name) 
    {
        vector<char> vowels = {'A', 'E', 'I', 'O', 'U', 'Y'};

        for (int i = 0; i < vowels.size(); i++) {
            if (name[0] == vowels[i]) return "Girl";
        }

        return "Boy";
    }
};