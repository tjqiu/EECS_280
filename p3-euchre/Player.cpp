//Project UID 1d9f47bfc76643019cfbf037641defe1
#include "Player.h"
#include "Card.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <array>

using namespace std;

static void printhand(int numCard, string name, vector<Card> &cards) {
    std::sort(cards.begin(), cards.end());
    for (int i = 0; i < numCard; ++i) {
        std::cout << "Human player " << name << "'s hand: [" << i << "] "
        << cards[i] << std::endl;
    }
}


class SimplePlayer:public Player {
public:
    SimplePlayer() {
        name = "Default Simple";
        index = 0;
        numCard = 0;
    }
    
    SimplePlayer(std::string nameInput) {
        name = nameInput;
        index = 0;
        numCard = 0;
    }
    
    const std::string & get_name() const {
        return name;
    }
    
    void add_card(const Card &c) {
        cards[index] = c;
        ++index;
        ++numCard;
    }
    
    bool make_trump(const Card &upcard, bool is_dealer,
                        int round, std::string &order_up_suit) const {
            if (round == 1) {
                        int numFace = 0;
                        for (int i = 0; i < MAX_HAND_SIZE; ++i) {
                            if ((cards[i].is_trump(upcard.get_suit())) &&
                                (cards[i].is_left_bower(upcard.get_suit()) ||
                                cards[i].is_right_bower(upcard.get_suit()) ||
                                    cards[i].is_face())) {
                                    ++numFace;
                                }
                        }
                if (numFace >= 2) {
                    order_up_suit = upcard.get_suit();
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                std::string trump = Suit_next(upcard.get_suit());
                for (int i = 0; i < MAX_HAND_SIZE; ++i) {
                    if ((cards[i].is_trump(trump))
                        && (cards[i].is_left_bower(trump) ||
                            cards[i].is_right_bower(trump) ||
                            cards[i].is_face())) {
                            order_up_suit = trump;
                            return true;
                        }
                    
                }
                if (is_dealer) {
                    order_up_suit = trump;
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    
    void add_and_discard(const Card &upcard) {
        Card lowest = cards[0];
        int lowestIndex = 0;
        for (int i = 0; i < MAX_HAND_SIZE; ++i) {
            if (Card_less(cards[i], lowest, upcard.get_suit())) {
                lowest = cards[i];
                lowestIndex = i;
            }
        }
        if (Card_less(lowest, upcard, upcard.get_suit())) {
            cards[lowestIndex] = upcard;
        }
    }
    
    Card lead_card(const std::string &trump) {
        std::array<Card, MAX_HAND_SIZE> nonTrump;
        int nonTrumpIndex = 0;
        std::array<int, MAX_HAND_SIZE> cardIndex;
        for (int i = 0; i < numCard; ++i) {
            if (!cards[i].is_trump(trump)) {
                nonTrump[nonTrumpIndex] = cards[i];
                cardIndex[nonTrumpIndex] = i;
                ++nonTrumpIndex;
            }
        }
        if (nonTrumpIndex == 0) {
            Card highest = cards[0];
            int highestIndex = 0;
            for (int i = 0; i < numCard; ++i) {
                if (Card_less(highest, cards[i], trump)) {
                    highest = cards[i];
                    highestIndex = i;
                }
            }
            for (int i = highestIndex+1; i < numCard; ++i) {
                cards[i-1] = cards[i];
            }
            --numCard;
            return highest;
        }
        else {
            Card highest = nonTrump[0];
            int highestIndex = 0;
            for (int i = 0; i < nonTrumpIndex; ++i) {
                if (Card_less(highest, nonTrump[i], trump)) {
                    highest = nonTrump[i];
                    highestIndex = i;
                }
            }
            for (int i = cardIndex[highestIndex]+1; i < numCard; ++i) {
                cards[i-1] = cards[i];
            }
            --numCard;
            return highest;
        }
    }
    
    Card play_card(const Card &led_card, const std::string &trump) {
        index = 0;
        std::array<Card, MAX_HAND_SIZE> followCard;
        std::array<int, MAX_HAND_SIZE> cardIndex;
        int followIndex = 0;
        for (int i = 0; i < numCard; ++i) {
            if (cards[i].get_suit(trump) == led_card.get_suit(trump)) {
                followCard[followIndex] = cards[i];
                cardIndex[followIndex] = i;
                ++followIndex;
            }
        }
        if (followIndex == 0) {
            Card lowest = cards[0];
            int lowestIndex = 0;
            for (int i = 0; i < numCard; ++i) {
                if (Card_less(cards[i], lowest, trump)) {
                    lowest = cards[i];
                    lowestIndex = i;
                }
            }
            for (int i = lowestIndex+1; i < numCard; ++i) {
                cards[i-1] = cards[i];
            }
            --numCard;
            return lowest;
        }
        else {
            Card highest = followCard[0];
            int highestIndex = 0;
            for (int i = 0; i < followIndex; ++i) {
                if (Card_less(highest, followCard[i], trump)) {
                    highest = followCard[i];
                    highestIndex = i;
                }
            }
            for (int i = cardIndex[highestIndex]+1; i < numCard; ++i) {
                cards[i-1] = cards[i];
            }
            --numCard;
            return highest;
        }
    }
    
private:
    std::string name;
    std::array<Card, MAX_HAND_SIZE> cards;
    int index;
    int numCard;
};

class HumanPlayer:public Player {
public:
    HumanPlayer() {
        name = "Default Human";
        index = 0;
        numCard = 0;
    }
    
    HumanPlayer(std::string nameInput) {
        name = nameInput;
        index = 0;
        numCard = 0;
    }
    
    const std::string & get_name() const {
        return name;
    }
    
    void add_card(const Card &c) {
        cards.push_back(c);
        ++index;
        ++numCard;
    }
    
    bool make_trump(const Card &upcard, bool is_dealer, int round,
                    std::string &order_up_suit) const {
        bool ret;
        vector<Card> cardsCopy = cards;
        std::sort(cardsCopy.begin(), cardsCopy.end());
        for (int i = 0; i < numCard; ++i) {
            std::cout << "Human player " << name << "'s hand: [" << i << "] "
            << cardsCopy[i] << std::endl;
        }
        cout << "Human player " << name
        << ", please enter a suit, or \"pass\":" << endl;
        std::string instruction;
        cin >> instruction;
        if (instruction == "pass") {
            ret = false;
        }
        else if (instruction == "Spades") {
            order_up_suit = SUIT_NAMES_BY_WEIGHT[0];
            ret = true;
        }
        else if (instruction == "Hearts") {
            order_up_suit = SUIT_NAMES_BY_WEIGHT[1];
            ret = true;
        }
        else if (instruction == "Clubs") {
            order_up_suit = SUIT_NAMES_BY_WEIGHT[2];
            ret = true;
        }
        else {
            order_up_suit = SUIT_NAMES_BY_WEIGHT[3];
            ret = true;
        }
        return ret;
    }
    
    void add_and_discard(const Card &upcard) {
        printhand(numCard, name, cards);
        cout << "Discard upcard: [-1]" << endl << "Human player " << name
        << ", please select a card to discard:" << endl;
        int instruction;
        cin >> instruction;
        if (instruction != -1) {
            cards[instruction] = upcard;
        }
    }
    
    Card lead_card(const std::string &trump) {
        printhand(numCard, name, cards);
        cout << "Human player " << name << ", please select a card:" << endl;
        int instruction;
        cin >> instruction;
        --numCard;
        Card ret = cards[instruction];
        cards.erase(cards.begin() + instruction);
        return ret;
    }
    
    Card play_card(const Card &led_card, const std::string &trump) {
        printhand(numCard, name, cards);
        cout << "Human player " << name << ", please select a card:" << endl;
        int instruction;
        cin >> instruction;
        index = 0;
        --numCard;
        Card ret = cards[instruction];
        cards.erase(cards.begin() + instruction);
        return ret;
    }
    
private:
    std::string name;
    std::vector<Card> cards;
    int index;
    int numCard;
    
};

Player * Player_factory(const std::string &name,
                        const std::string &strategy) {
    // We need to check the value of strategy and return
    // the corresponding player type.
    if (strategy == "Simple") {
        // The "new" keyword dynamically allocates an object.
        return new SimplePlayer(name);
    }
    // Repeat for each other type of Player
    else if (strategy == "Human") {
        return new HumanPlayer(name);
    }
    // Invalid strategy if we get here
    return nullptr;
}

std::ostream & operator<<(std::ostream &os, const Player &p) {
    os << p.get_name();
    return os;
}
