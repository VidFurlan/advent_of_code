#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> DP;

int getKey(int i, int bi, int current) {
    return (i << 20) | (bi << 10) | current;
}

int f(const string& dots, const vector<int>& blocks, int i, int bi, int current) {
    int key = getKey(i, bi, current);
    if (DP.find(key) != DP.end())
        return DP[key];

    if (i == dots.length())
        if ((bi == blocks.size() && current == 0) || (bi == blocks.size() - 1 && blocks[bi] == current)) 
            return 1;
        else 
            return 0;

    int ans = 0;
    for (char c : {'.', '#'}) {
        if (dots[i] == c || dots[i] == '?') 
            if (c == '.' && current == 0) 
                ans += f(dots, blocks, i + 1, bi, 0);
            else if (c == '.' && current > 0 && bi < blocks.size() && blocks[bi] == current) 
                ans += f(dots, blocks, i + 1, bi + 1, 0);
            else if (c == '#') 
                ans += f(dots, blocks, i + 1, bi, current + 1);
    }

    DP[key] = ans;
    return ans;
}

int main() {
    ifstream infile("input.txt");
    vector<string> springs;
    string line;
    while (getline(infile, line)) 
        springs.push_back(line);

    int ans = 0;
    for (const string& line : springs) {
        string dots, blocks_str;
        istringstream iss(line);
        iss >> dots >> blocks_str;

        vector<int> blocks;
        istringstream blocks_stream(blocks_str);
        int block;
        while (blocks_stream >> block) {
            blocks.push_back(block);
            if (blocks_stream.peek() == ',') 
                blocks_stream.ignore();
        }

        DP.clear();
        int score = f(dots, blocks, 0, 0, 0);
        ans += score;
    }

    cout << ans << endl;

    return 0;
}
