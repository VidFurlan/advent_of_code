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

    for (int i = 1; getline(input_file, input_line); i++) 
    {
        int pos = input_line.find(":");
        string value_line = input_line.substr(pos + 2);
        bool is_valid = true;

        while (!value_line.empty())
        {
            pos = value_line.find(";");
            string value = value_line;

            if (pos != string::npos) 
            {
                value = value_line.substr(0, pos);
                value_line = value_line.substr(pos + 2);
            }
            
            if (!(findColor(value, "red") <= 12 && findColor(value, "green") <= 13 && findColor(value, "blue") <= 14))
            {
                is_valid = false;
                break;
            }

            if (pos == string::npos)
                break;
        }
    
        if (is_valid) 
            ans += i;
    }
        
    cout << ans << endl;

    return 0;
}
