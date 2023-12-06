#include <iostream>
#include <fstream>
#include <string>
#include <string>
#include <algorithm>

using namespace std;

long int createSet(string str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return stol(str);
}

int main() {
    ifstream input_file("input.txt");
    string line;
    int ans = 1;
    
    getline(input_file, line);
    long int times = createSet(line.substr(line.find(":")+1, line.size()));

    getline(input_file, line); 
    long int records = createSet(line.substr(line.find(":")+1, line.size()));

    cout << "Time: " << times << "\nRecord: " << records << "\n";
    long int l = 0, r = times;

    for (; (times - l) * l <= records; l++); 
    for (; (times - r) * r <= records; r--); 

    cout << l << " - " << r << " -> " << r - l + 1 << "\n"; 

    return 0;
}
