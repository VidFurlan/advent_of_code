#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<char, int> card_map = {{'T',10}, {'J',11}, {'Q',12}, {'K',13}, {'A',14}};
struct card_hand {
    string cards;
    int power = 0;
    int worth;
};

int card_to_int (char card)
{
    if (isdigit(card))
        return card - 48;
    
    return card_map[card] + 1;
}

bool card_comp(card_hand h1, card_hand h2) {
    for (int i = 0; i < 5; i++)
        if (card_to_int(h1.cards[i]) != card_to_int(h2.cards[i])) {
            cout << h1.cards[i] << " " << card_to_int(h1.cards[i]) << " " << card_to_int(h2.cards[i]) << endl;
            return card_to_int(h1.cards[i]) < card_to_int(h2.cards[i]); 
        }
    return true;
}

int main () {
    int combos[5] = {0, 1, 3, 5, 6};
    vector<vector<card_hand>> hands_by_pow(7);

    ifstream input_file("input.txt");
    string line;
    while (getline(input_file, line)) 
    {
        card_hand hand;
        hand.cards = line.substr(0, 5);
        hand.worth = stoi(line.substr(6, line.size()));

        unordered_map<char, int> cards_count;
        for (char card : hand.cards)
            cards_count[card]++;

        for (auto card : cards_count)
            hand.power += combos[card.second - 1];

        hands_by_pow[hand.power].push_back(hand);
        cout << hand.cards << ", " << hand.power << ", " << hand.worth << endl;
    }
    int ans = 0, i = 1;
    for (auto hands : hands_by_pow){
        sort(hands.begin(), hands.end(), card_comp);
        for (auto hand : hands) {
            ans += i * hand.worth;
            cout << hand.cards << " " << hand.power <<" "<< hand.worth << " " << i << " " << hand.worth * i << endl;
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}
