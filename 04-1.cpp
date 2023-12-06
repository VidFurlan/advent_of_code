#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;

unordered_set<int> createSet(string str) {
    unordered_set<int> numbers;
    istringstream iss(str);
    
    int number;
    while (iss >> number) 
        numbers.insert(number);
    
    return numbers;
}

int main() {
    ifstream input_file("input.txt");
    string line;
    int ans = 0;
    
    unordered_map<int, int> map;
    while (getline(input_file, line)) 
    {
        int card_num = stoi(line.substr(line.find(" ") + 1, line.find(":") - 1));
        map[card_num]++;
        unordered_set<int> win_nums = createSet(line.substr(line.find(":") + 2, line.find("|") - 1));
        unordered_set<int> elf_nums = createSet(line.substr(line.find("|") + 1, line.size()));
        
        int found = 0;
        for (auto num : win_nums)
            if (elf_nums.find(num) != elf_nums.end())
                found++;

        for (; found > 0; found--) {
            map[card_num+found] += map[card_num];    
        }

        ans += map[card_num];
        cout << ans << endl;
    }

    return 0;
}
