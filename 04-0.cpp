#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <unordered_set>
 
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
    
    while (getline(input_file, line)) 
    {
        unordered_set<int> win_nums = createSet(line.substr(line.find(":") + 2, line.find("|") - 1));
        unordered_set<int> elf_nums = createSet(line.substr(line.find("|") + 1, line.size()));
        
        int found = -1;
        for (auto num : win_nums)
            if (elf_nums.find(num) != elf_nums.end())
                found++;

        ans += (found != -1) ? pow(2,found) : 0;
        cout << ans << endl;
    }

    return 0;
}
