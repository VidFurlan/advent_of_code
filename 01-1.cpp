#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;

vector<string> words = {"one","two","three","four","five","six","seven","eight","nine"};

int checkForNumber(string line, int start_index, int end_index) {
  string substring = line.substr(start_index, end_index);

  for (int i = 0; i < words.size(); i++)
    if (substring.find(words[i]) != string::npos)
      return i + 1;

  return 0;
}

int main() {
    string line;
    int sum = 0;

    while (getline(cin, line)) 
    {
      int num = 0;
      for (int i = 0; i < line.size(); i++)
      {
        if (checkForNumber(line,0,i))
        {
          num += checkForNumber(line,0,i) * 10;
          break;
        }
        else if (isdigit(line[i]))
        {
          num += (line[i] - 48) * 10;
          break;
        }
      }

      for (int i = line.size()-1; i >= 0; i--)
        if (checkForNumber(line,i,line.size()-1))
        {
          num += checkForNumber(line,i,line.size()-1);
          break;
        }
        else if (isdigit(line[i]))
        {
          num += (line[i] - 48);
          break;
        }

      sum += num;
      
      cout << "\n" << sum;
    }
    
    return 0;
}
