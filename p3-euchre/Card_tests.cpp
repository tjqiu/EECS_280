// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Card.h"
#include "unit_test_framework.h"
#include <iostream>

using namespace std;


TEST(test_card_ctor) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Card::RANK_ACE, c.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, c.get_suit());
}

TEST(test_card_suit_and_rank) {
    Card two_spades = Card();
    ASSERT_EQUAL(two_spades.get_rank(), Card::RANK_TWO);
    ASSERT_EQUAL(two_spades.get_suit(), Card::SUIT_SPADES);

    Card three_spades = Card(Card::RANK_THREE, Card::SUIT_SPADES);
    ASSERT_EQUAL(three_spades.get_rank(), Card::RANK_THREE);
    ASSERT_EQUAL(three_spades.get_suit(), Card::SUIT_SPADES);
    ASSERT_EQUAL(three_spades.get_suit(Card::SUIT_CLUBS), Card::SUIT_SPADES);
}

TEST(test_card_type) {
    Card three_spades = Card(Card::RANK_THREE, Card::SUIT_SPADES);
    ASSERT_FALSE(three_spades.is_face());
    ASSERT_FALSE(three_spades.is_right_bower(Card::SUIT_CLUBS));
    ASSERT_FALSE(three_spades.is_left_bower(Card::SUIT_CLUBS));
    ASSERT_FALSE(three_spades.is_trump(Card::SUIT_CLUBS));
}

TEST(test_card_self_comparison) {
    Card three_spades = Card(Card::RANK_THREE, Card::SUIT_SPADES);
    ASSERT_FALSE(three_spades < three_spades);
    ASSERT_TRUE(three_spades <= three_spades);
    ASSERT_FALSE(three_spades > three_spades);
    ASSERT_TRUE(three_spades >= three_spades);
    ASSERT_TRUE(three_spades == three_spades);
    ASSERT_FALSE(three_spades != three_spades);
}

TEST(test_Suit_next) {
    ASSERT_EQUAL(Suit_next(Card::SUIT_CLUBS), Card::SUIT_SPADES);
}

TEST(test_Card_less_self) {
    Card three_spades = Card(Card::RANK_THREE, Card::SUIT_SPADES);
    ASSERT_FALSE(Card_less(three_spades, three_spades, Card::SUIT_CLUBS));
    ASSERT_FALSE(Card_less(three_spades, three_spades, three_spades,
                           Card::SUIT_CLUBS));
}

TEST(test_card_insertion) {
    Card three_spades = Card(Card::RANK_THREE, Card::SUIT_SPADES);
    ostringstream oss;
    oss << three_spades;
    ASSERT_EQUAL(oss.str(), "Three of Spades");
}

TEST(test_card_default_ctor) {
    Card c;
    ASSERT_EQUAL(Card::RANK_TWO, c.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, c.get_suit());
}

TEST(test_card_nond_ctor) {
    Card c(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_EQUAL(Card::RANK_ACE, c.get_rank());
    ASSERT_EQUAL(Card::SUIT_CLUBS, c.get_suit());
}

TEST(test_get_suit_trump) {
    Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_EQUAL(Card::SUIT_CLUBS, c.get_suit(Card::SUIT_HEARTS));
    ASSERT_EQUAL(Card::SUIT_SPADES, c.get_suit(Card::SUIT_SPADES));
    ASSERT_EQUAL(Card::SUIT_CLUBS, c.get_suit(Card::SUIT_CLUBS));
}

TEST(test_face) {
    Card c(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_TRUE(c.is_face());
    Card d(Card::RANK_TWO, Card::SUIT_CLUBS);
    ASSERT_FALSE(d.is_face());
}

TEST(test_right) {
    Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_TRUE(c.is_right_bower(Card::SUIT_CLUBS));
    ASSERT_FALSE(c.is_right_bower(Card::SUIT_SPADES));
}

TEST(test_left) {
    Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_FALSE(c.is_left_bower(Card::SUIT_CLUBS));
    ASSERT_TRUE(c.is_left_bower(Card::SUIT_SPADES));
}

TEST(test_trump) {
    Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_TRUE(c.is_trump(Card::SUIT_CLUBS));
    ASSERT_TRUE(c.is_trump(Card::SUIT_SPADES));
    Card d(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_TRUE(d.is_trump(Card::SUIT_CLUBS));
    ASSERT_FALSE(d.is_trump(Card::SUIT_SPADES));
}

TEST(test_less) {
    Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card d(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card e(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_TRUE(c < d);
    ASSERT_TRUE(c < e);
    ASSERT_TRUE(d < e);
}

TEST(test_less_equal) {
    Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card d(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card e(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card f(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_TRUE(c <= d);
    ASSERT_TRUE(c <= e);
    ASSERT_TRUE(d <= e);
    ASSERT_TRUE(e <= f);
}

TEST(test_larger) {
    Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card d(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card e(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_TRUE(d > c);
    ASSERT_TRUE(e > c);
    ASSERT_TRUE(e > d);
}

TEST(test_larger_equal) {
    Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card d(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card e(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card f(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_TRUE(d >= c);
    ASSERT_TRUE(e >= c);
    ASSERT_TRUE(e >= d);
    ASSERT_TRUE(f >= e);
}

TEST(test_equal) {
    Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card d(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card e(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card f(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_TRUE(e == f);
    ASSERT_FALSE(c == e);
    ASSERT_FALSE(d == e);
}

TEST(test_non_equal) {
    Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card d(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card e(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card f(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_FALSE(e != f);
    ASSERT_TRUE(c != e);
    ASSERT_TRUE(d != f);
}

TEST(test_suit_next) {
    ASSERT_EQUAL(Card::SUIT_SPADES, Suit_next(Card::SUIT_CLUBS));
    ASSERT_EQUAL(Card::SUIT_HEARTS, Suit_next(Card::SUIT_DIAMONDS));
}

TEST(test_os) {
    Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    ostringstream oss;
    oss << c;
    ASSERT_EQUAL("Jack of Clubs", oss.str());
}

TEST(test_card_less) {
    Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card d(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card e(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card f(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card a(Card::RANK_JACK, Card::SUIT_SPADES);
    Card b(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    ASSERT_TRUE(Card_less(e, c, Card::SUIT_CLUBS));
    ASSERT_FALSE(Card_less(e, f, Card::SUIT_CLUBS));
    ASSERT_TRUE(Card_less(d, e, Card::SUIT_CLUBS));
    ASSERT_TRUE(Card_less(a, c, Card::SUIT_CLUBS));
    ASSERT_TRUE(Card_less(e, a, Card::SUIT_CLUBS));
    ASSERT_TRUE(Card_less(b, d, Card::SUIT_CLUBS));
}

TEST(test_card_less_led) {
    Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card d(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card e(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card f(Card::RANK_NINE, Card::SUIT_CLUBS);
    Card a(Card::RANK_JACK, Card::SUIT_SPADES);
    Card b(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    ASSERT_TRUE(Card_less(c, d, c, Card::SUIT_HEARTS));
    ASSERT_TRUE(Card_less(d, f, d, Card::SUIT_CLUBS));
    ASSERT_TRUE(Card_less(b, d, d, Card::SUIT_CLUBS));
    ASSERT_TRUE(Card_less(d, a, d, Card::SUIT_CLUBS));
    ASSERT_TRUE(Card_less(a, c, d, Card::SUIT_CLUBS));
    ASSERT_TRUE(Card_less(e, a, d, Card::SUIT_CLUBS));
}
// Add more test cases here

TEST_MAIN()
