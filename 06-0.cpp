#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> splitToNums(string str) {
    istringstream iss(str);
    vector<int> tokens;
    string token;

    while (iss >> token) {
        if (!token.empty()) {
            tokens.push_back(stoi(token));
        }
    }

    return tokens;
}

int main() {
    ifstream input_file("input.txt");
    string line;
    
    getline(input_file, line);
    vector<int> times = splitToNums(line.substr(line.find(":")+1, line.size()));

    getline(input_file, line); 
    vector<int> records = splitToNums(line.substr(line.find(":")+1, line.size()));

    int ans = 1;
    for (int i = 0; i < times.size(); i++) {
        cout << "Time: " << times[i] << "\nRecord: " << records[i] << "\n";
        int l = 0, r = times[times.size()-1];

        for (; (times[i] - l) * l <= records[i]; l++); 
        for (; (times[i] - r) * r <= records[i]; r--); 

        cout << l << " - " << r << " -> " << r - l + 1 << "\n"; 
        ans *= r - l + 1; 
    }

    cout << "\nAns: " << ans << endl;

    return 0;
}
