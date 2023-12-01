#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

int main() {
    string line;
    int sum = 0;

    while (getline(cin, line)) 
    {
      int num = 0;
      for (int i = 0; i < line.size(); i++)
        if (isdigit(line[i]))
        {
          num += (line[i] - 48) * 10;
          break;
        }

      for (int i = line.size()-1; i >= 0; i--)
        if (isdigit(line[i]))
        {
          num += line[i] - 48;
          break;
        }

      sum += num;

      cout << sum << '\n';
    }

    return 0;
}
