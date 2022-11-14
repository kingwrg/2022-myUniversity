#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>

using namespace std;

class SimpleCompressor
{
    public:
    // string uncompress(string data) 
    // {
    //     if (!(data.find('[') != string::npos)) {
    //         return data;
    //     }

    //     std::size_t start = data.find_last_of('[');
    //     std::size_t end = data.find_first_of(']', start+1);

    //     int numb = data[start+1] - '0';
    //     string sequence = data.substr(start + 2, (end - start) - 2);

    //     data.erase(start, (end - start) + 1);

    //     string repeat = "";
    //     for (int i = 0 ; i < numb; i++) {
    //         repeat += sequence;
    //     }
    //     data.insert(start, repeat);
        
    //     return uncompress(data);
    // }

    string uncompress(string data) 
    {
        stack<int> opens;
        
        int m = 0;
        while (data.find('[') != string::npos) {
            for (int j = m; j < data.length(); j++) {
                if (data[j] == '[') 
                    opens.push(j);
                else if (data[j] == ']') {
                    int i = opens.top();
                    opens.pop();

                    string buf = "";
                    buf += data.substr(0, i);

                    for (int k = 0; k < data[i+1] - '0'; k++) 
                        buf += data.substr(i+2, j - i - 2);
                    
                    m = buf.length();
                    buf += data.substr(j+1);
                    data = buf;
                    break;
                }
                cout << data << endl;
            }
        }
        return data;
    }
};