#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

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

int sumUpLine (vector<int> nums) {
    vector<int> new_nums;
    bool zeros = true;
    for (int i = 0; i < nums.size()-1; i++) {
        new_nums.push_back(nums[i+1] - nums[i]);
        if (nums[i+1] - nums[i]) {
            zeros = false;
        }
    }

    cout << endl;
    for (int num : new_nums)
        cout << num << " ";

    if (zeros)
        return 0;

    return sumUpLine(new_nums) + new_nums[new_nums.size() - 1];
}

int main () {
    ifstream input_file("input.txt");
    string line;
    int ans = 0;

    while (getline(input_file, line)) {
        vector<vector<int>> rows = {splitToNums(line)};

        for (auto nums : rows) {
            ans += sumUpLine(nums) + nums[nums.size()-1];
            cout << sumUpLine(nums) + nums[nums.size()-1] << endl; 
        }
    }

    cout << ans << endl;

    return 0;
}
