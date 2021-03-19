// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Player.h"
#include "unit_test_framework.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

TEST(test_player_insertion) {
    Player * human = Player_factory("NotRobot", "Human");
    ostringstream oss;
    oss << * human;
    ASSERT_EQUAL(oss.str(), "NotRobot");
    oss.str("");
    Player * alice = Player_factory("Alice", "Simple");
    oss << *alice;
    ASSERT_EQUAL(oss.str(), "Alice");
    oss.str("");
    delete alice;
    delete human;
}

TEST(test_insertion2) {
    ostringstream oss;
    Player * nullName = Player_factory("", "Human");
    oss << *nullName;
    ASSERT_EQUAL(oss.str(), "");
    delete nullName;
}

TEST(test_simple_player_get_name) {
  Player * alice = Player_factory("Alice", "Simple");
  ASSERT_EQUAL(alice->get_name(), "Alice");
  delete alice;
}

static void add_cards(Player *player) {
  Card two_spades = Card(Card::RANK_TWO, Card::SUIT_SPADES);
  for (int i = 0; i < 5; ++i) {
    player->add_card(two_spades);
  }
}

TEST(test_simple_player_make_trump) {
  Player * bob = Player_factory("Bob", "Simple");
  add_cards(bob);

  Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
  string trump = Card::SUIT_SPADES;
  bool orderup = bob->make_trump(
      nine_spades,    //upcard
      true,           //Bob is also the dealer
      1,              //first round
      trump           //suit ordered up (if any)
  );
  ASSERT_FALSE(orderup);
  ASSERT_EQUAL(trump, Card::SUIT_SPADES);

  delete bob;
}

TEST(test_simple_player_lead_card) {
  Player * bob = Player_factory("Bob", "Simple");
  add_cards(bob);
  Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
  bob->add_and_discard(nine_spades);
  Card card_led = bob->lead_card(Card::SUIT_SPADES);
  ASSERT_EQUAL(card_led, nine_spades); //check led card
  delete bob;
}

TEST(test_simple_player_play_card) {
  Player * bob = Player_factory("Bob", "Simple");
  add_cards(bob);
  Card nine_diamonds(Card::RANK_NINE, Card::SUIT_DIAMONDS);
  string trump = Card::SUIT_HEARTS;
  Card card_played = bob->play_card(nine_diamonds, trump); //Diamonds is led
  Card two_spades = Card(Card::RANK_TWO, Card::SUIT_SPADES);
  ASSERT_EQUAL(card_played, two_spades);
  delete bob;
}

TEST(test_player_get_name2) {
    Player * alice = Player_factory("Alice", "Human");
    ASSERT_EQUAL("Alice", alice->get_name());
    delete alice;
}

static void add_cards2(Player *player) {
    Card one = Card(Card::RANK_JACK, Card::SUIT_SPADES);
    Card two = Card(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card three = Card(Card::RANK_TWO, Card::SUIT_SPADES);
    Card four = Card(Card::RANK_TWO, Card::SUIT_SPADES);
    Card five = Card(Card::RANK_TWO, Card::SUIT_SPADES);
    player->add_card(one);
    player->add_card(two);
    player->add_card(three);
    player->add_card(four);
    player->add_card(five);
}

TEST(test_simple_player_make_trump2) {
  Player * bob = Player_factory("Bob", "Simple");
  add_cards2(bob);

  Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
  string trump = Card::SUIT_SPADES;
  bool orderup = bob->make_trump(
      nine_spades,    //upcard
      true,           //Bob is also the dealer
      1,              //first round
      trump           //suit ordered up (if any)
  );
  ASSERT_TRUE(orderup);
  ASSERT_EQUAL(trump, Card::SUIT_SPADES);

  delete bob;
}

// Add more tests here

static void add_cards3(Player *player) {
    Card one = Card(Card::RANK_JACK, Card::SUIT_SPADES);
    Card two = Card(Card::RANK_ACE, Card::SUIT_SPADES);
    Card three = Card(Card::RANK_TWO, Card::SUIT_SPADES);
    Card four = Card(Card::RANK_TWO, Card::SUIT_SPADES);
    Card five = Card(Card::RANK_TWO, Card::SUIT_SPADES);
    player->add_card(one);
    player->add_card(two);
    player->add_card(three);
    player->add_card(four);
    player->add_card(five);
}

TEST(test_simple_player_make_trump3) {
  Player * bob = Player_factory("Bob", "Simple");
  add_cards3(bob);

  Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
  string trump = Card::SUIT_SPADES;
  bool orderup = bob->make_trump(
      nine_spades,    //upcard
      true,           //Bob is also the dealer
      1,              //first round
      trump           //suit ordered up (if any)
  );
  ASSERT_TRUE(orderup);
  ASSERT_EQUAL(trump, Card::SUIT_SPADES);

  delete bob;
}

static void add_cards4(Player *player) {
    Card one = Card(Card::RANK_KING, Card::SUIT_SPADES);
    Card two = Card(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card three = Card(Card::RANK_TWO, Card::SUIT_SPADES);
    Card four = Card(Card::RANK_TWO, Card::SUIT_SPADES);
    Card five = Card(Card::RANK_TWO, Card::SUIT_SPADES);
    player->add_card(one);
    player->add_card(two);
    player->add_card(three);
    player->add_card(four);
    player->add_card(five);
}

TEST(test_simple_player_make_trump4) {
  Player * bob = Player_factory("Bob", "Simple");
  add_cards4(bob);

  Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
  string trump = Card::SUIT_SPADES;
  bool orderup = bob->make_trump(
      nine_spades,    //upcard
      true,           //Bob is also the dealer
      1,              //first round
      trump           //suit ordered up (if any)
  );
  ASSERT_TRUE(orderup);
  ASSERT_EQUAL(trump, Card::SUIT_SPADES);

  delete bob;
}

static void add_cards5(Player *player) {
    Card one = Card(Card::RANK_JACK, Card::SUIT_SPADES);
    Card two = Card(Card::RANK_TEN, Card::SUIT_SPADES);
    Card three = Card(Card::RANK_TWO, Card::SUIT_SPADES);
    Card four = Card(Card::RANK_TWO, Card::SUIT_SPADES);
    Card five = Card(Card::RANK_TWO, Card::SUIT_SPADES);
    player->add_card(one);
    player->add_card(two);
    player->add_card(three);
    player->add_card(four);
    player->add_card(five);
}

TEST(test_simple_player_make_trump5) {
  Player * bob = Player_factory("Bob", "Simple");
  add_cards5(bob);

  Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
  string trump = Card::SUIT_SPADES;
  bool orderup = bob->make_trump(
      nine_spades,    //upcard
      true,           //Bob is also the dealer
      1,              //first round
      trump           //suit ordered up (if any)
  );
  ASSERT_FALSE(orderup);
  ASSERT_EQUAL(trump, Card::SUIT_SPADES);

  delete bob;
}

TEST(test_simple_player_make_trump6) {
    Player* bob = Player_factory("Bob", "Simple");
    Card upcard = Card(Card::RANK_KING, Card::SUIT_HEARTS);
    string trump = Card::SUIT_HEARTS;

    Card king_diamonds = Card(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card ten_clubs = Card(Card::RANK_TEN, Card::SUIT_CLUBS);
    Card nine_clubs = Card(Card::RANK_NINE, Card::SUIT_CLUBS);
    Card ten_hearts = Card(Card::RANK_TEN, Card::SUIT_HEARTS);
    Card nine_hearts = Card(Card::RANK_NINE, Card::SUIT_HEARTS);

    bob->add_card(king_diamonds);
    bob->add_card(ten_clubs);
    bob->add_card(nine_clubs);
    bob->add_card(ten_hearts);
    bob->add_card(nine_hearts);

    bool orderup = bob->make_trump(upcard, false, 2, trump);
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_DIAMONDS);

    delete bob;
}

TEST(test_simple_player_make_trump7) {
    Player* bob = Player_factory("Bob", "Simple");
    Card upcard = Card(Card::RANK_ACE, Card::SUIT_HEARTS);
    string trump = Card::SUIT_HEARTS;

    Card ten_clubs = Card(Card::RANK_TEN, Card::SUIT_CLUBS);
    Card ten_diamonds = Card(Card::RANK_TEN, Card::SUIT_DIAMONDS);
    Card nine_diamonds = Card(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    Card ten_hearts = Card(Card::RANK_TEN, Card::SUIT_HEARTS);
    Card nine_hearts = Card(Card::RANK_NINE, Card::SUIT_HEARTS);

    bob->add_card(ten_clubs);
    bob->add_card(ten_diamonds);
    bob->add_card(nine_diamonds);
    bob->add_card(ten_hearts);
    bob->add_card(nine_hearts);

    bool orderup = bob->make_trump(upcard, false, 2, trump);
    ASSERT_FALSE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_HEARTS);

    delete bob;
}

TEST(test_simple_player_make_trump8) {
    Player* bob = Player_factory("Bob", "Simple");
    Card upcard = Card(Card::RANK_ACE, Card::SUIT_HEARTS);
    string trump = Card::SUIT_HEARTS;

    Card jack_diamonds = Card(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card ten_diamonds = Card(Card::RANK_TEN, Card::SUIT_DIAMONDS);
    Card nine_diamonds = Card(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    Card ten_hearts = Card(Card::RANK_TEN, Card::SUIT_HEARTS);
    Card nine_hearts = Card(Card::RANK_NINE, Card::SUIT_HEARTS);

    bob->add_card(jack_diamonds);
    bob->add_card(ten_diamonds);
    bob->add_card(nine_diamonds);
    bob->add_card(ten_hearts);
    bob->add_card(nine_hearts);

    bool orderup = bob->make_trump(upcard, false, 2, trump);
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_DIAMONDS);

    delete bob;
}

//screw the dealer evoked
TEST(test_simple_player_make_trump9) {
    Player* bob = Player_factory("Bob", "Simple");
    Card upcard = Card(Card::RANK_ACE, Card::SUIT_HEARTS);
    string trump = Card::SUIT_HEARTS;

    Card king_diamonds = Card(Card::RANK_KING, Card::SUIT_CLUBS);
    Card ten_diamonds = Card(Card::RANK_TEN, Card::SUIT_SPADES);
    Card nine_diamonds = Card(Card::RANK_NINE, Card::SUIT_CLUBS);
    Card ten_hearts = Card(Card::RANK_TEN, Card::SUIT_SPADES);
    Card nine_hearts = Card(Card::RANK_NINE, Card::SUIT_CLUBS);

    bob->add_card(king_diamonds);
    bob->add_card(ten_diamonds);
    bob->add_card(nine_diamonds);
    bob->add_card(ten_hearts);
    bob->add_card(nine_hearts);

    bool orderup = bob->make_trump(upcard, true, 2, trump);
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_DIAMONDS);
    
    delete bob;
}

TEST(test_simple_player_make_trump10) {
    Player* bob = Player_factory("Bob", "Simple");
    Card upcard = Card(Card::RANK_ACE, Card::SUIT_HEARTS);
    string trump = Card::SUIT_HEARTS;

    Card king_diamonds = Card(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card ten_diamonds = Card(Card::RANK_TEN, Card::SUIT_HEARTS);
    Card nine_diamonds = Card(Card::RANK_NINE, Card::SUIT_CLUBS);
    Card ten_hearts = Card(Card::RANK_TEN, Card::SUIT_SPADES);
    Card nine_hearts = Card(Card::RANK_NINE, Card::SUIT_CLUBS);

    bob->add_card(king_diamonds);
    bob->add_card(ten_diamonds);
    bob->add_card(nine_diamonds);
    bob->add_card(ten_hearts);
    bob->add_card(nine_hearts);

    bool orderup = bob->make_trump(upcard, false, 1, trump);
    ASSERT_FALSE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_HEARTS);
    
    delete bob;
}

TEST(test_simple_player_make_trump11) {
    Player* bob = Player_factory("Bob", "Simple");
    Card upcard = Card(Card::RANK_ACE, Card::SUIT_HEARTS);
    string trump = Card::SUIT_HEARTS;

    Card king_diamonds = Card(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card ten_diamonds = Card(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card nine_diamonds = Card(Card::RANK_NINE, Card::SUIT_CLUBS);
    Card ten_hearts = Card(Card::RANK_TEN, Card::SUIT_SPADES);
    Card nine_hearts = Card(Card::RANK_NINE, Card::SUIT_CLUBS);

    bob->add_card(king_diamonds);
    bob->add_card(ten_diamonds);
    bob->add_card(nine_diamonds);
    bob->add_card(ten_hearts);
    bob->add_card(nine_hearts);

    bool orderup = bob->make_trump(upcard, false, 1, trump);
    ASSERT_FALSE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_HEARTS);
    
    delete bob;
}

TEST(test_simple_player_make_trump12) {
    Player* bob = Player_factory("Bob", "Simple");
    Card upcard = Card(Card::RANK_ACE, Card::SUIT_HEARTS);
    string trump = Card::SUIT_HEARTS;

    Card king_diamonds = Card(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card ten_diamonds = Card(Card::RANK_KING, Card::SUIT_SPADES);
    Card nine_diamonds = Card(Card::RANK_NINE, Card::SUIT_CLUBS);
    Card ten_hearts = Card(Card::RANK_TEN, Card::SUIT_SPADES);
    Card nine_hearts = Card(Card::RANK_NINE, Card::SUIT_CLUBS);

    bob->add_card(king_diamonds);
    bob->add_card(ten_diamonds);
    bob->add_card(nine_diamonds);
    bob->add_card(ten_hearts);
    bob->add_card(nine_hearts);

    bool orderup = bob->make_trump(upcard, false, 2, trump);
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_DIAMONDS);
    
    delete bob;
}

TEST(test_simple_player_make_trump13) {
    Player* bob = Player_factory("Bob", "Simple");
    Card upcard = Card(Card::RANK_ACE, Card::SUIT_HEARTS);
    string trump = Card::SUIT_HEARTS;

    Card king_diamonds = Card(Card::RANK_KING, Card::SUIT_HEARTS);
    Card ten_diamonds = Card(Card::RANK_KING, Card::SUIT_SPADES);
    Card nine_diamonds = Card(Card::RANK_NINE, Card::SUIT_CLUBS);
    Card ten_hearts = Card(Card::RANK_TEN, Card::SUIT_SPADES);
    Card nine_hearts = Card(Card::RANK_NINE, Card::SUIT_CLUBS);

    bob->add_card(king_diamonds);
    bob->add_card(ten_diamonds);
    bob->add_card(nine_diamonds);
    bob->add_card(ten_hearts);
    bob->add_card(nine_hearts);

    bool orderup = bob->make_trump(upcard, false, 2, trump);
    ASSERT_FALSE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_HEARTS);
    
    delete bob;
}

TEST(test_simple_player_make_trump14) {
    Player* bob = Player_factory("Bob", "Simple");
    Card upcard = Card(Card::RANK_ACE, Card::SUIT_HEARTS);
    string trump = Card::SUIT_HEARTS;

    Card king_diamonds = Card(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card ten_diamonds = Card(Card::RANK_KING, Card::SUIT_SPADES);
    Card nine_diamonds = Card(Card::RANK_NINE, Card::SUIT_CLUBS);
    Card ten_hearts = Card(Card::RANK_TEN, Card::SUIT_SPADES);
    Card nine_hearts = Card(Card::RANK_NINE, Card::SUIT_CLUBS);

    bob->add_card(king_diamonds);
    bob->add_card(ten_diamonds);
    bob->add_card(nine_diamonds);
    bob->add_card(ten_hearts);
    bob->add_card(nine_hearts);

    bool orderup = bob->make_trump(upcard, false, 2, trump);
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_DIAMONDS);
    
    delete bob;
}

TEST(test_simple_player_play_card1) {
    Player* bob = Player_factory("Bob", "Simple");

    Card lead_card = Card(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    string trump = Card::SUIT_SPADES;

    Card king_diamonds = Card(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card queen_diamonds = Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
    Card ten_clubs = Card(Card::RANK_TEN, Card::SUIT_CLUBS);
    Card nine_clubs = Card(Card::RANK_NINE, Card::SUIT_CLUBS);
    Card ten_spades = Card(Card::RANK_TEN, Card::SUIT_SPADES);

    bob->add_card(king_diamonds);
    bob->add_card(queen_diamonds);
    bob->add_card(ten_clubs);
    bob->add_card(nine_clubs);
    bob->add_card(ten_spades);

    ASSERT_EQUAL(bob->play_card(lead_card, trump), king_diamonds);

    delete bob;
}

TEST(test_simple_player_play_card2) {
    Player* bob = Player_factory("Bob", "Simple");

    Card lead_card = Card(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    string trump = Card::SUIT_SPADES;

    Card king_clubs = Card(Card::RANK_KING, Card::SUIT_CLUBS);
    Card queen_clubs = Card(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card ten_clubs = Card(Card::RANK_TEN, Card::SUIT_CLUBS);
    Card nine_clubs = Card(Card::RANK_NINE, Card::SUIT_CLUBS);
    Card ten_spades = Card(Card::RANK_TEN, Card::SUIT_SPADES);

    bob->add_card(king_clubs);
    bob->add_card(queen_clubs);
    bob->add_card(ten_clubs);
    bob->add_card(nine_clubs);
    bob->add_card(ten_spades);

    ASSERT_EQUAL(bob->play_card(lead_card, trump), nine_clubs);

    delete bob;
}

TEST(test_simple_player_add_and_discard1) {
    Player* bob = Player_factory("Bob", "Simple");

    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    Card nine_diamonds(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    Card ten_diamonds(Card::RANK_TEN, Card::SUIT_DIAMONDS);
    Card jack_diamonds(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card queen_diamonds(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
    Card king_diamonds(Card::RANK_KING, Card::SUIT_DIAMONDS);

    bob->add_card(nine_spades);
    bob->add_card(nine_diamonds);
    bob->add_card(ten_diamonds);
    bob->add_card(queen_diamonds);
    bob->add_card(king_diamonds);

    bob->add_and_discard(jack_diamonds);

    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), jack_diamonds);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), king_diamonds);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), queen_diamonds);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), ten_diamonds);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), nine_diamonds);

    delete bob;
}

TEST(test_simple_player_add_and_discard2) {
    Player* bob = Player_factory("Bob", "Simple");

    Card ace_spades(Card::RANK_ACE, Card::SUIT_SPADES);
    Card ace_diamonds(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    Card king_diamonds(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card queen_diamonds(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
    Card jack_diamonds(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card jack_spades(Card::RANK_JACK, Card::SUIT_SPADES);

    bob->add_card(jack_diamonds);
    bob->add_card(ace_diamonds);
    bob->add_card(king_diamonds);
    bob->add_card(queen_diamonds);
    bob->add_card(ace_spades);

    bob->add_and_discard(jack_spades);

    ASSERT_EQUAL(bob->lead_card(Card::SUIT_SPADES), ace_diamonds);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_SPADES), king_diamonds);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_SPADES), queen_diamonds);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_SPADES), jack_spades);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_SPADES), ace_spades);

    delete bob;
}

TEST(test_simple_player_add_and_discard3) {
    Player* bob = Player_factory("Bob", "Simple");

    Card ace_diamonds(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    Card king_diamonds(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card queen_diamonds(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
    Card jack_diamonds(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card ten_diamonds(Card::RANK_TEN, Card::SUIT_DIAMONDS);
    Card nine_diamonds(Card::RANK_NINE, Card::SUIT_DIAMONDS);

    bob->add_card(jack_diamonds);
    bob->add_card(ace_diamonds);
    bob->add_card(king_diamonds);
    bob->add_card(queen_diamonds);
    bob->add_card(ten_diamonds);

    bob->add_and_discard(nine_diamonds);

    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), jack_diamonds);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), ace_diamonds);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), king_diamonds);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), queen_diamonds);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), ten_diamonds);

    delete bob;
}

TEST(test_simple_player_add_and_discard4) {
    Player* bob = Player_factory("Bob", "Simple");

    Card ace_diamonds(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    Card king_diamonds(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card queen_diamonds(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
    Card jack_diamonds(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card ten_diamonds(Card::RANK_TEN, Card::SUIT_DIAMONDS);
    Card nine_diamonds(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    Card jack_heart(Card::RANK_JACK, Card::SUIT_HEARTS);

    bob->add_card(jack_diamonds);
    bob->add_card(ace_diamonds);
    bob->add_card(nine_diamonds);
    bob->add_card(jack_heart);
    bob->add_card(ten_diamonds);

    bob->add_and_discard(king_diamonds);

    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), jack_diamonds);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), jack_heart);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), ace_diamonds);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), king_diamonds);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), ten_diamonds);

    delete bob;
}

TEST(test_simple_player_add_and_discard5) {
    Player* bob = Player_factory("Bob", "Simple");

    Card ten_club(Card::RANK_TEN, Card::SUIT_CLUBS);
    Card king_diamonds(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card queen_diamonds(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
    Card jack_diamonds(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card ten_diamonds(Card::RANK_TEN, Card::SUIT_DIAMONDS);
    Card ten_spades(Card::RANK_TEN, Card::SUIT_SPADES);
    Card ten_heart(Card::RANK_TEN, Card::SUIT_HEARTS);

    bob->add_card(jack_diamonds);
    bob->add_card(ten_club);
    bob->add_card(ten_spades);
    bob->add_card(ten_heart);
    bob->add_card(ten_diamonds);

    bob->add_and_discard(king_diamonds);

    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), ten_club);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), ten_heart);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), jack_diamonds);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), king_diamonds);
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), ten_diamonds);

    delete bob;
}

TEST(test_simple_player_lead_card1) {
    Player* bob = Player_factory("Bob", "Simple");

    Card nine_spades = Card(Card::RANK_NINE, Card::SUIT_SPADES);
    Card ten_spades = Card(Card::RANK_TEN, Card::SUIT_SPADES);
    Card jack_spades = Card(Card::RANK_JACK, Card::SUIT_SPADES);
    Card nine_diamonds = Card(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    Card ten_diamonds = Card(Card::RANK_TEN, Card::SUIT_DIAMONDS);

    bob->add_card(nine_spades);
    bob->add_card(ten_spades);
    bob->add_card(jack_spades);
    bob->add_card(nine_diamonds);
    bob->add_card(ten_diamonds);

    ASSERT_EQUAL(bob->lead_card(Card::SUIT_SPADES), ten_diamonds);

    delete bob;
}

TEST(test_simple_player_lead_card2) {
    Player* bob = Player_factory("Bob", "Simple");

    Card jack_clubs = Card(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card ace_diamonds = Card(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    Card king_diamonds = Card(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card queen_diamonds = Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
    Card jack_diamonds = Card(Card::RANK_JACK, Card::SUIT_DIAMONDS);

    bob->add_card(jack_clubs);
    bob->add_card(ace_diamonds);
    bob->add_card(king_diamonds);
    bob->add_card(queen_diamonds);
    bob->add_card(jack_diamonds);

    ASSERT_EQUAL(bob->lead_card(Card::SUIT_SPADES), ace_diamonds);

    delete bob;
}

TEST(test_simple_player_lead_card3) {
    Player* bob = Player_factory("Bob", "Simple");

    Card jack_spades = Card(Card::RANK_JACK, Card::SUIT_SPADES);
    Card ace_spades = Card(Card::RANK_ACE, Card::SUIT_SPADES);
    Card king_diamonds = Card(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card king_clubs = Card(Card::RANK_KING, Card::SUIT_CLUBS);
    Card king_hearts = Card(Card::RANK_KING, Card::SUIT_HEARTS);

    bob->add_card(jack_spades);
    bob->add_card(ace_spades);
    bob->add_card(king_diamonds);
    bob->add_card(king_clubs);
    bob->add_card(king_hearts);

    ASSERT_EQUAL(bob->lead_card(Card::SUIT_SPADES), king_diamonds);

    delete bob;
}

TEST(test_simple_player_lead_card4) {
    Player* bob = Player_factory("Bob", "Simple");

    Card ace_diamonds = Card(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    Card king_diamonds = Card(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card queen_diamonds = Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
    Card jack_diamonds = Card(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card ten_diamonds = Card(Card::RANK_TEN, Card::SUIT_DIAMONDS);

    bob->add_card(ace_diamonds);
    bob->add_card(king_diamonds);
    bob->add_card(queen_diamonds);
    bob->add_card(jack_diamonds);
    bob->add_card(ten_diamonds);

    ASSERT_EQUAL(bob->lead_card(Card::SUIT_HEARTS), ace_diamonds);

    delete bob;
}

/*
TEST(test_ostream) {
    stringstream ss;
    Player* bob = Player_factory("Bob", "Simple");
    ss << bob;
    string test;
    ss >> test;
    ASSERT_EQUAL(test, bob);
    delete bob;
}
*/
TEST_MAIN()
