#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

vector<int> movePos(vector<int> pos, const vector<int> move) {
    pos[0] += move[0];
    pos[1] += move[1];
    return pos;
}

int main () {
    unordered_map<char, vector<vector<int>>> dict = {
        {'|', { {0, -1}, {0, 1}  }},
        {'-', { {-1, 0}, {1, 0}  }},
        {'L', { {0, -1}, {1, 0}  }},
        {'J', { {0, -1}, {-1, 0} }},
        {'7', { {-1, 0}, {0, 1}  }},
        {'F', { {0, 1} , {1, 0}  }}
    };

    ifstream input_file("input.txt");
    string line;

    int ans = 0, x_size = 0, y_size = 0;
    vector<int> s_pos;
    vector<vector<char>> map;

    for (; getline(input_file, line); y_size++) {
        x_size = line.size();
        map.push_back({});

        for (int i = 0; i < line.size(); i++) {
            map[map.size()-1].push_back(line[i]);
            cout << line[i] << " ";
            if (line[i] == 'S')
                s_pos = {i, y_size};
        }

        cout << endl;
    }
    
    cout << x_size << " " << y_size << " " << s_pos[0] << " " << s_pos[1] << endl;

    vector<vector<int>> moves = {
        {0,  1 },
        {0,  -1},
        {1,  0 },
        {-1, 0 },
    };

    for (auto move : moves) {
        vector<int> pos = s_pos;
        vector<int> next_pos = movePos(pos, move);
        
        int ans = 0;

        if (pos[0] < 0 || pos[0] >= x_size || pos[1] < 0 || pos[1] >= y_size)
            continue;

        while (pos[0] >= 0 && pos[0] < x_size && pos[1] >= 0 && pos[1] < y_size) {
            if (map[pos[1]][pos[0]] == '.' || (map[pos[1]][pos[0]] == 'S' && ans != 0)) {
                break;
            }

            ans++;

            if (map[next_pos[1]][next_pos[0]] == 'S')
            {
                cout << "ANS: " << ans/2.0 << endl;
                return 0;
            }

            cout << " -> " << map[pos[1]][pos[0]] << endl;

            vector<int> nextPos1 = movePos(next_pos, dict[map[next_pos[1]][next_pos[0]]][0]);
            vector<int> nextPos2 = movePos(next_pos, dict[map[next_pos[1]][next_pos[0]]][1]);

            cout << nextPos1[0] << " " << nextPos1[1] << "\n";
            cout << nextPos2[0] << " " << nextPos2[1] << "\n";
            cout << pos[0] << " " << pos[1] << "\n";

            if (nextPos1 == pos) { 
                pos = next_pos;
                next_pos = nextPos2;
            }
            else if (nextPos2 == pos) {
                pos = next_pos;
                next_pos = nextPos1;
            }
            else 
                break;
            cout << "Found next: \n";
        }
    }

    return 0;
}
