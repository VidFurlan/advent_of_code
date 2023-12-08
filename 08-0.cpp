#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;
    
int main ()
{
      ifstream input_file("input.txt");
      string line, dirs;
      getline(input_file, dirs);
      unordered_map<string, pair<string, string>> map;

      while (getline(input_file, line)) {
          if (line == "")
              continue;
          map[line.substr(0, 3)] = {line.substr(7, 3), line.substr(12,3)};
          cout << line << endl;
      }

      string str = "AAA";
      int ans = 0;
      for (; str != "ZZZ"; ans++)
          if (dirs[ans % dirs.size()] == 'L')
              str = map[str].first;
          else 
              str = map[str].second;

      cout << ans << endl;
      return 0;
}
