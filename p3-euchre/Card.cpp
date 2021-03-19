// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cassert>
#include <iostream>
#include <string>
#include "Card.h"
// add any necessary #include or using directives here

// rank and suit names -- do not remove these
constexpr const char* const Card::RANK_TWO;
constexpr const char* const Card::RANK_THREE;
constexpr const char* const Card::RANK_FOUR;
constexpr const char* const Card::RANK_FIVE;
constexpr const char* const Card::RANK_SIX;
constexpr const char* const Card::RANK_SEVEN;
constexpr const char* const Card::RANK_EIGHT;
constexpr const char* const Card::RANK_NINE;
constexpr const char* const Card::RANK_TEN;
constexpr const char* const Card::RANK_JACK;
constexpr const char* const Card::RANK_QUEEN;
constexpr const char* const Card::RANK_KING;
constexpr const char* const Card::RANK_ACE;

constexpr const char* const Card::SUIT_SPADES;
constexpr const char* const Card::SUIT_HEARTS;
constexpr const char* const Card::SUIT_CLUBS;
constexpr const char* const Card::SUIT_DIAMONDS;

// add your code below
Card::Card()
: rank(RANK_NAMES_BY_WEIGHT[0]), suit(SUIT_NAMES_BY_WEIGHT[0]) {}

Card::Card(const std::string &rank_in, const std::string &suit_in) {
    for (int i = 0; i < NUM_RANKS; ++i) {
        if (rank_in == RANK_NAMES_BY_WEIGHT[i]) {
            rank = RANK_NAMES_BY_WEIGHT[i];
        }
    }
    for (int i = 0; i < NUM_SUITS; ++i) {
        if (suit_in == SUIT_NAMES_BY_WEIGHT[i]) {
            suit = SUIT_NAMES_BY_WEIGHT[i];
        }
    }
}

std::string Card::get_rank() const {
    return rank;
}

std::string Card::get_suit() const {
    return suit;
}

std::string Card::get_suit(const std::string &trump) const {
    if (rank == RANK_NAMES_BY_WEIGHT[9]) {
        if (trump == SUIT_NAMES_BY_WEIGHT[0] ||
            trump == SUIT_NAMES_BY_WEIGHT[2]) {
            if (suit == SUIT_NAMES_BY_WEIGHT[0] ||
                suit == SUIT_NAMES_BY_WEIGHT[2]) {
                return trump;
            }
            else {
                return get_suit();
            }
        }
        else {
            if (suit == SUIT_NAMES_BY_WEIGHT[1] ||
                suit == SUIT_NAMES_BY_WEIGHT[3]) {
                return trump;
            }
            else {
                return get_suit();
            }
        }
    }
    else {
        return get_suit();
    }
}

bool Card::is_face() const {
    return (get_rank() == RANK_NAMES_BY_WEIGHT[9] ||
            get_rank() == RANK_NAMES_BY_WEIGHT[10] ||
            get_rank() == RANK_NAMES_BY_WEIGHT[11] ||
            get_rank() == RANK_NAMES_BY_WEIGHT[12]);
}

bool Card::is_right_bower(const std::string &trump) const {
    return (get_rank() == RANK_NAMES_BY_WEIGHT[9] && get_suit() == trump);
}

bool Card::is_left_bower(const std::string &trump) const {
    return (get_suit() != get_suit(trump));
}

bool Card::is_trump(const std::string &trump) const {
    return (get_suit(trump) == trump);
}

bool operator<(const Card &lhs, const Card &rhs) {
    if (lhs.get_rank() != rhs.get_rank()) {
        int leftIndex = 0;
        int rightIndex = 0;
        for (int i = 0; i < NUM_RANKS; ++i) {
            if (RANK_NAMES_BY_WEIGHT[i] == lhs.get_rank()) {
                leftIndex = i;
            }
            if (RANK_NAMES_BY_WEIGHT[i] == rhs.get_rank()) {
                rightIndex = i;
            }
        }
        return (leftIndex < rightIndex);
    }
    else {
        int leftIndex = 0;
        int rightIndex = 0;
        for (int i = 0; i < NUM_SUITS; ++i) {
            if (SUIT_NAMES_BY_WEIGHT[i] == lhs.get_suit()) {
                leftIndex = i;
            }
            if (SUIT_NAMES_BY_WEIGHT[i] == rhs.get_suit()) {
                rightIndex = i;
            }
        }
        return (leftIndex < rightIndex);
    }
}

bool operator==(const Card &lhs, const Card &rhs) {
    return ((lhs.get_rank() == rhs.get_rank()) &&
            (lhs.get_suit() == rhs.get_suit()));
}

bool operator<=(const Card &lhs, const Card &rhs) {
    return (lhs < rhs || lhs == rhs);
}

bool operator>(const Card &lhs, const Card &rhs) {
    return !(lhs <= rhs);
}

bool operator>=(const Card &lhs, const Card &rhs) {
    return !(lhs < rhs);
}

bool operator!=(const Card &lhs, const Card &rhs) {
    return !(lhs == rhs);
}

std::string Suit_next(const std::string &suit) {
    if (suit == SUIT_NAMES_BY_WEIGHT[0]) {
        return SUIT_NAMES_BY_WEIGHT[2];
    }
    else if (suit == SUIT_NAMES_BY_WEIGHT[2]) {
        return SUIT_NAMES_BY_WEIGHT[0];
    }
    else if (suit == SUIT_NAMES_BY_WEIGHT[1]) {
        return SUIT_NAMES_BY_WEIGHT[3];
    }
    else {
        return SUIT_NAMES_BY_WEIGHT[1];
    }
}

std::ostream & operator<<(std::ostream &os, const Card &card) {
    os << card.get_rank() << " of " << card.get_suit();
    return os;
}

bool Card_less(const Card &a, const Card &b, const std::string &trump) {
    if (a.is_trump(trump) && !b.is_trump(trump)) {
        return false;
    }
    else if (b.is_trump(trump) && !a.is_trump(trump)) {
        return true;
    }
    else if (!a.is_trump(trump) && !b.is_trump(trump)) {
        return (a < b);
    }
    if (a.get_rank() == b.get_rank() &&
        a.get_rank() != RANK_NAMES_BY_WEIGHT[9] &&
        b.get_rank() != RANK_NAMES_BY_WEIGHT[9]) {
        return (a < b);
    }
    else {
        if (a.is_left_bower(trump)) {
            if (b.is_right_bower(trump)) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if (a.is_right_bower(trump)) {
                return false;
            }
            if (b.is_left_bower(trump) || b.is_right_bower(trump)) {
                return true;
            }
            else {
                return (a < b);
            }
            
        }
        
    }
}

bool Card_less(const Card &a, const Card &b, const Card &led_card,
               const std::string &trump) {
    if (led_card.get_suit(trump) == trump) {
        return Card_less(a, b, trump);
    }
    else {
        if (a.is_trump(trump) || b.is_trump(trump)) {
            return Card_less(a, b, trump);
        }
        else {
            if (a.get_suit() == led_card.get_suit() &&
                b.get_suit() == led_card.get_suit()) {
                return (a < b);
            }
            else if (a.get_suit() == led_card.get_suit() &&
                     !(b.get_suit() == led_card.get_suit())) {
                return false;
            }
            else if (!(a.get_suit() == led_card.get_suit()) &&
                     b.get_suit() == led_card.get_suit()) {
                return true;
            }
            else {
                return (a < b);
            }
        }
    }
}
// NOTE: We HIGHLY recommend you check out the operator overloading
// tutorial in the project spec (see the appendices) before implementing
// the following operator overload functions:
//   operator<<
//   operator<
//   operator<=
//   operator>
//   operator>=
//   operator==
//   operator!=
