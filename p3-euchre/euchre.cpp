//Project UID 1d9f47bfc76643019cfbf037641defe1
#include "Card.h"
#include "Player.h"
#include "Pack.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

const int NUM_OF_PLAYER = 4;

class Game {
public:
    Game() {
        score[0] = 0;
        score[1] = 0;
        finalScore[0] = 0;
        finalScore[1] = 0;
        for (int i = 0; i < NUM_OF_PLAYER; ++i) {
            win[i] = 0;
        }
        dealerIndex = 0;
        leaderIndex = 1;
    }
    
    void setplayer(int indexPlayer, string name, string strategy){
        player[indexPlayer] = Player_factory(name, strategy);
    }
    
    void setup(std::istream& pack_input) {
        Pack input(pack_input);
        pack = input;
    }
    
    void shuffle(string ifShuffle) {
        if (ifShuffle == "shuffle") {
            pack.shuffle();
        }
        else {
            pack.reset();
        }
    }
    
    void dealHelper(int deal, int &dealIndex) {
        if (deal % 2 == 0) {
            for (int j = 0; j < 3; ++j) {
                player[dealIndex]->add_card(pack.deal_one());
            }
            dealIndex = (dealIndex + 1) % 4;
        }
        else {
            for (int j = 0; j < 2; ++j) {
                player[dealIndex]->add_card(pack.deal_one());
            }
            dealIndex = (dealIndex + 1) % 4;
        }
    }
    
    void deal() {
            int dealIndex = (dealerIndex + 1) % 4;
            int deal = 0;
            for (int i = 0; i < 2; ++i) {
                for (int k = 0; k < 4; ++k) {
                    dealHelper(deal, dealIndex);
                    ++deal;
                }
                ++deal;
            }
            upcard = pack.deal_one();
        }
    
    void makeTrump() {
        int round = 1;
        for (int i = 1; i < NUM_OF_PLAYER+1; ++i) {
            bool isDealer = ((dealerIndex+i)%4 == 0);
            if (player[(dealerIndex+i)%4]->make_trump(upcard,isDealer,
                                                      round, trump)) {
                cout << player[(dealerIndex+i)%4]->get_name() << " orders up "
                << trump << endl;
                orderIndex = (dealerIndex+i)%4;
                ++round;
                break;
            }
            else {
                cout << player[(dealerIndex+i)%4]->get_name() << " passes"
                << endl;
            }
        }
        if (round == 2) {
            player[dealerIndex%4]->add_and_discard(upcard);
        }
        if (round == 1) {
            for (int i = 1; i < NUM_OF_PLAYER; ++i) {
                bool isDealer = ((dealerIndex+i)%4 == 0);
                if (player[(dealerIndex+i)%4]->make_trump(upcard, isDealer,
                                                          round+1, trump)) {
                    orderIndex = (dealerIndex+i)%4;
                    cout << player[(dealerIndex+i)%4]->get_name()
                    << " orders up " << trump << endl;
                    ++round;
                    break;
                }
                else {
                    cout << player[(dealerIndex+i)%4]->get_name() << " passes"
                    << endl;
                }
            }
        }
        if (round == 1) {
            trump = Suit_next(upcard.get_suit());
            orderIndex = dealerIndex;
            cout << player[dealerIndex]->get_name() << " orders up " << trump
            << endl;
        }
        cout << endl;
    }
    
    void playTrick() {
        for (int i = 0; i < 5; ++i) {
            array<Card, 4> playCard;
            playCard[0] = player[leaderIndex%4]->lead_card(trump);
            cout << playCard[0] << " led by "
            << player[leaderIndex%4]->get_name() << endl;
            playCard[1] = player[(leaderIndex+1)%4]->play_card(playCard[0],
                                                               trump);
            cout << playCard[1] << " played by "
            << player[(leaderIndex+1)%4]->get_name() << endl;
            playCard[2] = player[(leaderIndex+2)%4]->play_card(playCard[0],
                                                               trump);
            cout << playCard[2] << " played by "
            << player[(leaderIndex+2)%4]->get_name() << endl;
            playCard[3] = player[(leaderIndex+3)%4]->play_card(playCard[0],
                                                               trump);
            cout << playCard[3] << " played by "
            << player[(leaderIndex+3)%4]->get_name() << endl;
            int winner = leaderIndex%4;
            Card winCard = playCard[0];
            for (int i = 0; i < 4; ++i) {
                if (Card_less(winCard, playCard[i], playCard[0], trump)) {
                    winner = (leaderIndex+i)%4;
                    winCard = playCard[i];
                }
            }
            cout << player[winner]->get_name() << " takes the trick" << endl
            << endl;
            ++win[winner];
            leaderIndex = winner;
        }
    }
    
    void scoreCal() {
        int teamWin[2];
        teamWin[0] = win[0] + win[2];
        teamWin[1] = win[1] + win[3];
        if (orderIndex == 0 || orderIndex == 2) {
            if (teamWin[0] == 3 || teamWin[0] == 4) {
                ++score[0];
                cout << player[0]->get_name() << " and "
                << player[2]->get_name() << " win the hand" << endl;
            }
            else if (teamWin[0] == 5) {
                score[0] += 2;
                cout << player[0]->get_name() << " and "
                << player[2]->get_name() << " win the hand" << endl;
                cout << "march!" << endl;
            }
            else {
                score[1] += 2;
                cout << player[1]->get_name() << " and "
                << player[3]->get_name() << " win the hand" << endl;
                cout << "euchred!" << endl;
            }
        }
        else if (orderIndex == 1 || orderIndex == 3) {
            if (teamWin[1] == 3 || teamWin[1] == 4) {
                cout << player[1]->get_name() << " and "
                << player[3]->get_name() << " win the hand" << endl;
                ++score[1];
            }
            else if (teamWin[1] == 5) {
                cout << player[1]->get_name() << " and "
                << player[3]->get_name() << " win the hand" << endl;
                score[1] += 2;
                cout << "march!" << endl;
            }
            else {
                cout << player[0]->get_name() << " and "
                << player[2]->get_name() << " win the hand" << endl;
                score[0] += 2;
                cout << "euchred!" << endl;
            }
        }
    }
    
    int getScore(int index) {
        return finalScore[index];
    }
    
    void setDealer(int dealer) {
        dealerIndex = dealer;
        leaderIndex = dealerIndex + 1;
    }
    
    Player* getPlayer(int index) {
        return player[index];
    }
    
    Card getUpcard() {
        return upcard;
    }
    
    void printScore() {
        finalScore[0] += score[0];
        finalScore[1] += score[1];
        cout << player[0]->get_name() << " and " << player[2]->get_name()
        << " have " << finalScore[0] << " points" << endl;
        cout << player[1]->get_name() << " and " << player[3]->get_name()
        << " have " << finalScore[1] << " points" << endl << endl;
        score[0] = 0;
        score[1] = 0;
        win[0] = 0;
        win[1] = 0;
        win[2] = 0;
        win[3] = 0;
    }
    
    void printWinner() {
        if (finalScore[0] > finalScore[1]) {
            cout << player[0]->get_name() << " and " << player[2]->get_name()
            << " win!" << endl;
        }
        else {
            cout << player[1]->get_name() << " and " << player[3]->get_name()
            << " win!" << endl;
        }
    }
    
    void deletePlayer() {
        delete player[0];
        delete player[1];
        delete player[2];
        delete player[3];
    }
    
private:
    Player* player[NUM_OF_PLAYER];
    Pack pack;
    int score[2];
    int dealerIndex;
    Card upcard;
    string trump;
    int leaderIndex;
    int win[NUM_OF_PLAYER];
    int orderIndex;
    int finalScore[2];
};




int main(int argc, char** argv) {
    string shuf = argv[2];
    string type1 = argv[5];
    string type2 = argv[7];
    string type3 = argv[9];
    string type4 = argv[11];
    if (argc != 12 || atoi(argv[3]) < 1 || atoi(argv[3]) > 100 ||
        (shuf != "shuffle" && shuf != "noshuffle") ||
        (type1 != "Simple" && type1 != "Human") ||
        (type2 != "Simple" && type2 != "Human") ||
        (type3 != "Simple" && type3 != "Human") ||
        (type4 != "Simple" && type4 != "Human")) {
        cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
             << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
             << "NAME4 TYPE4" << endl;
        return 1;
    }
    for (int i = 0; i < argc; ++i) {
        cout << argv[i] << " ";
    }
    cout << endl;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin.is_open()) {
        cout << "Error opening " << argv[1] << endl;
        return 1;
    }
    Game game;
    game.setup(fin);
    int hand = 0;
    int dealer = 0;
    for (int i = 0; i< 7; i += 2) {
        game.setplayer(i/2, argv[i+4], argv[i+5]);
    }
    while (game.getScore(0) < atoi(argv[3]) &&
           game.getScore(1) < atoi(argv[3])) {
        cout << "Hand " << hand << endl;
        cout << game.getPlayer(dealer%4)->get_name() << " deals" << endl;
        game.shuffle(argv[2]);
        game.deal();
        cout << game.getUpcard() << " turned up" << endl;
        game.makeTrump();
        game.playTrick();
        game.scoreCal();
        game.printScore();
        ++hand;
        ++dealer;
        game.setDealer(dealer);
    }
    game.printWinner();
    game.deletePlayer();
    return 0;
}
