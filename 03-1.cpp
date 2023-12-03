#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

int main () {
    vector<string> rows;

    ifstream input_file("input.txt");
    string input_line;
    
    while (getline(input_file, input_line)) 
        rows.push_back(input_line);
    
    int ans = 0;

    for (int i = 0; i < rows.size(); i++) {
        for (int j = 0; j < rows[i].size(); j++) {
            if (rows[i][j] != '*')
                continue;
            
            unordered_set<string> set;

            for (int cur_row = i - 1; cur_row <= i + 1; cur_row++) {
                for (int cur_col = j - 1; cur_col <= j + 1; cur_col++) {
                    if (cur_row < 0 || cur_row >= rows.size() || cur_col < 0 || cur_col >= rows[cur_row].size() || !(isdigit(rows[cur_row][cur_col])))
                        continue;
                    
                    int col = cur_col;
                    while (col > 0 && isdigit(rows[cur_row][col - 1])) 
                        col--;
                    
                    set.insert(to_string(cur_row) + "." + to_string(col));
                }
            }

            if (set.size() != 2)
                continue;
            
            vector<int> nums;
            for (string pos : set)
            {
                int val = 0;
                int row = stoi(pos.substr(0, pos.find(".")));
                int col = stoi(pos.substr(pos.find(".") + 1, pos.size()));

                while (col < rows[row].size() && isdigit(rows[row][col])) {
                    val = val * 10 + rows[row][col] - 48;
                    col++;
                }
                
                nums.push_back(val);
            }

            ans += nums[0] * nums[1];
        }
    }
    
    cout << ans << endl;

    return 0;
}
