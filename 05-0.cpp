#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> splitNums(string str) {
    vector<int> nums;
    istringstream iss(str);

    int num;
    while (iss >> num) 
        nums.push_back(num);
    
    return nums;
}

int main () {
    ifstream input_file("input.txt");
    string line;
    int ans = 0;

    // Vector 1 -> For each step
    // Vector 2 -> For each line on step
    // Vector 3 -> For each number
    vector<vector<vector<int>>> map;

    while (getline(input_file, line)) {
        if (line == "" || !isdigit(line[0]))
            continue;
        if (!isdigit(line[0])) {
            map.push_back({});
            continue;
        }

        //map[map.size() - 1].push_back(splitNums(line));
        for (auto n : splitNums(line))
            cout << n << " ";
        cout << "\n";
    }

    return 0;
}
