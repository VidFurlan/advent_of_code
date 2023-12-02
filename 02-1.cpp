#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

int findColor (string line, string color)
{ 
    if (line.find(color) != string::npos) 
    {
        string substring = line.substr(0,line.find(color));
        if (substring.find(",") != string::npos) 
            substring = substring.substr(substring.find_last_of(",") + 2);
        return stoi(substring);
    }

    return 0;
}

int main() 
{
    ifstream input_file("input.txt");
    string input_line;
    int ans = 0;

    while (getline(input_file, input_line)) 
    {
        unordered_map<char, int> min_map;

        int pos = input_line.find(":");
        string value_line = input_line.substr(pos + 2);

        while (!value_line.empty())
        {
            pos = value_line.find(";");
            string value = value_line;

            if (pos != string::npos) 
            {
                value = value_line.substr(0, pos);
                value_line = value_line.substr(pos + 2);
            }
            
            min_map['r'] = max(min_map['r'], findColor(value, "red"));
            min_map['g'] = max(min_map['g'], findColor(value, "green"));
            min_map['b'] = max(min_map['b'], findColor(value, "blue"));

            if (pos == string::npos)
                break;
        }

        ans += (min_map['r'] * min_map['g'] * min_map['b']);
    }
        
    cout << ans << endl;

    return 0;
}
