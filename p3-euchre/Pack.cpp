// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include "Pack.h"
#include "Card.h"

using namespace std;

Pack::Pack() {
    next = 0;
    int cardIndex = 0;
    int rankStart = 7;
    for (int i = 0; i < NUM_SUITS; ++i) {
        for (int j = rankStart; j < NUM_RANKS; ++j) {
            Card c(RANK_NAMES_BY_WEIGHT[j], SUIT_NAMES_BY_WEIGHT[i]);
            cards[cardIndex] = c;
            ++cardIndex;
        }
    }
}

Pack::Pack(std::istream& pack_input) {
    next = 0;
    string rank;
    string of;
    string suit;
    int index = 0;
    while (pack_input >> rank >> of >> suit) {
        Card c(rank, suit);
        cards[index] = c;
        ++index;
    }
}

Card Pack::deal_one() {
    ++next;
    return cards[next - 1];
}

void Pack::reset() {
    next = 0;
}

void Pack::shuffle() {
    next = 0;
    std::array<Card, PACK_SIZE> cardsCopy = cards;
    for (int i = 0; i < 7; ++i) {
        cardsCopy = cards;
        for (int j = 0; j < 24; ++j) {
            if (j % 2 == 1) {
                cards[j] = cardsCopy[j / 2];
            }
            else {
                cards[j] = cardsCopy[12 + j / 2];
            }
        }
    }
}

bool Pack::empty() const {
    if (next == 24) {
        return true;
    }
    else {
        return false;
    }
}
