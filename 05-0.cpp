#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main () {
    ifstream input_file("input.txt");
    string line;
    int ans = 0;
    vector<vector<vector<int>>> step;

    for (int i = 0; getline(input_file, line); i++) {
        if (line == "")
            continue;

        cout << line << "\n";
    }

    return 0;
}