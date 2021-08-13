// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(test_default_ctor) {
    List<int> o;
    ASSERT_TRUE(o.empty());
}

TEST(test_empty) {
    List<int> o;
    ASSERT_TRUE(o.empty());
    o.push_back(3);
    ASSERT_FALSE(o.empty());
    o.pop_front();
    ASSERT_TRUE(o.empty());
}

TEST(test_size) {
    List<int> o;
    for (int i = 0; i < 13; ++i) {
        o.push_front(3);
    }
    ASSERT_TRUE(o.size() == 13);
    for (int i = 0; i< 3; ++i) {
        o.push_back(3);
    }
    ASSERT_TRUE(o.size() == 16);
    for (int i = 0; i < 9; ++i) {
        o.pop_front();
    }
    ASSERT_TRUE(o.size() == 7);
    for (int i = 0; i < 3; ++i) {
        o.pop_back();
    }
    ASSERT_EQUAL(o.size(), 4);
    for (int i = 0; i < 4; ++i) {
        o.pop_front();
    }
    ASSERT_EQUAL(o.size(), 0);
}

TEST(test_size2) {
    List<char> o;
    ASSERT_EQUAL(o.size(), 0);
}

TEST(test_size_itor) {
    List<int> o;
    o.push_front(0);
    List<int>::Iterator i = o.begin();
    o.insert(i, 3);
    ASSERT_EQUAL(o.size(), 2);
    ASSERT_TRUE(o.front() == 3);
    ASSERT_EQUAL(o.back(), 0);
    o.erase(i);
    ASSERT_EQUAL(o.size(), 1);
    ASSERT_TRUE(o.front() == 3);
    ASSERT_EQUAL(o.back(), 3);
    i = o.begin();
    o.erase(i);
    ASSERT_EQUAL(o.size(), 0);
}

TEST(test_front1) {
    List<int> o;
    o.push_front(3);
    ASSERT_EQUAL(o.front(), 3);
    o.push_front(13);
    ASSERT_EQUAL(o.front(), 13);
    o.push_back(9);
    ASSERT_EQUAL(o.front(), 13);
    o.pop_front();
    ASSERT_EQUAL(o.front(), 3);
}

TEST(test_front2) {
    List<int> i;
    i.push_back(3);
    ASSERT_EQUAL(i.front(), 3);
}

TEST(test_back1) {
    List<int> o;
    o.push_front(3);
    ASSERT_EQUAL(o.back(), 3);
    o.push_front(13);
    ASSERT_EQUAL(o.back(), 3);
    o.push_back(9);
    ASSERT_EQUAL(o.back(), 9);
    o.pop_back();
    ASSERT_EQUAL(o.back(), 3);
}

TEST(test_back2) {
    List<int> i;
    i.push_back(3);
    ASSERT_EQUAL(i.back(), 3);
}

TEST(test_push) {
    List<int> o;
    o.push_back(3);
    ASSERT_EQUAL(o.front(), 3);
    ASSERT_EQUAL(o.back(), 3);
    o.push_front(13);
    ASSERT_EQUAL(o.front(), 13);
    ASSERT_EQUAL(o.back(), 3);
    o.push_back(0);
    ASSERT_EQUAL(o.front(), 13);
    ASSERT_EQUAL(o.back(), 0);
    o.clear();
    o.push_front(3);
    ASSERT_EQUAL(o.front(), 3);
    ASSERT_EQUAL(o.back(), 3);
}

TEST(test_pop1) {
    List<double> o;
    o.push_front(3);
    o.pop_back();
    ASSERT_TRUE(o.empty());
    o.push_back(3);
    o.pop_front();
    ASSERT_TRUE(o.empty());
}

TEST(test_pop2) {
    List<double> o;
    o.push_back(3);
    o.push_back(9);
    o.pop_front();
    ASSERT_EQUAL(o.front(), 9);
    ASSERT_EQUAL(o.back(), 9);
}

TEST(test_pop3) {
    List<double> o;
    o.push_back(3);
    o.push_back(9);
    o.pop_back();
    ASSERT_EQUAL(o.front(), 3);
    ASSERT_EQUAL(o.back(), 3);
    o.pop_front();
    ASSERT_TRUE(o.empty());
}

TEST(test_clear) {
    List<double> o;
    o.push_front(3);
    o.push_back(9);
    o.push_front(12);
    ASSERT_EQUAL(o.front(), 12);
    ASSERT_EQUAL(o.back(), 9);
    o.clear();
    ASSERT_TRUE(o.empty());
}

TEST(test_clear2) {
    List<double> o;
    o.clear();
    ASSERT_TRUE(o.empty());
}

TEST(test_copy1) {
    List<double> o;
    o.push_front(3);
    o.push_back(9);
    o.push_front(12);
    List<double> i(o);
    ASSERT_EQUAL(o.front(), i.front());
    ASSERT_EQUAL(o.back(), o.back());
    o.pop_front();
    i.pop_front();
    ASSERT_EQUAL(o.front(), i.front());
    o.pop_back();
    ASSERT_EQUAL(i.back(), 9);
    ASSERT_EQUAL(o.back(), 3);
}

TEST(test_copy2) {
    List<double> o;
    ASSERT_TRUE(o.empty());
    List<double> i(o);
    ASSERT_TRUE(i.empty());
}

TEST(test_equal1) {
    List<double> o;
    o.push_front(3);
    o.push_back(9);
    o.push_front(12);
    List<double> i;
    i = o;
    ASSERT_EQUAL(o.front(), i.front());
    ASSERT_EQUAL(o.back(), o.back());
    o.pop_front();
    i.pop_front();
    ASSERT_EQUAL(o.front(), i.front());
    o.pop_back();
    ASSERT_EQUAL(i.back(), 9);
    ASSERT_EQUAL(o.back(), 3);
}

TEST(test_equal2) {
    List<double> o;
    ASSERT_TRUE(o.empty());
    List<double> i;
    i = o;
    ASSERT_TRUE(i.empty());
}

TEST(test_equal3) {
    List<double> o;
    o.push_front(3);
    o.push_back(9);
    o.push_front(12);
    o = o;
    ASSERT_FALSE(o.empty());
    ASSERT_EQUAL(o.front(), 12);
    ASSERT_EQUAL(o.back(), 9);
    List<double> j;
    List<double> k;
    j = k = o;
    ASSERT_FALSE(j.empty());
    ASSERT_EQUAL(j.front(), 12);
    ASSERT_EQUAL(j.back(), 9);
    ASSERT_EQUAL(k.front(), 12);
    ASSERT_EQUAL(k.back(), 9);
}

TEST(test_it_deref) {
    List<double> o;
    o.push_front(3);
    o.push_back(9);
    o.push_front(12);
    ASSERT_EQUAL(*(o.begin()), 12);
    ASSERT_EQUAL(*(++o.begin()), 3);
    List<double>::Iterator i;
    i = o.begin();
    ++++i;
    --i;
    ASSERT_EQUAL(*i, 3);
    ++i;
    ASSERT_EQUAL(*i, 9);
    ----i;
    ASSERT_EQUAL(*i, 12);
}

TEST(test_it_deref_edge) {
    List<double> o;
    o.push_back(1);
    ASSERT_EQUAL(*(o.begin()), 1);
}

TEST(test_it_begin) {
    List<double> o;
    o.push_back(1);
    o.push_back(4);
    ASSERT_EQUAL(*(o.begin()), 1);
    o.push_front(3);
    ASSERT_EQUAL(*(o.begin()), 3);
}

TEST(test_it_begin_edge) {
    List<double> o;
    o.push_back(1);
    ASSERT_EQUAL(*(o.begin()), 1);
    o.push_front(3);
    ASSERT_EQUAL(*(o.begin()), 3);
}

TEST(test_it_end) {
    List<double>::Iterator i;
    List<double> o;
    ASSERT_TRUE(o.end() == i);
}

TEST(test_it_plus) {
    List<double> o;
    o.push_front(3);
    o.push_back(9);
    o.push_front(12);
    ASSERT_EQUAL(*(++o.begin()), 3);
}

TEST(test_it_plus_edge) {
    List<double> o;
    o.push_back(1);
    o.push_back(4);
    ASSERT_EQUAL(*(++o.begin()), 4);
}

TEST(test_it_equal) {
    List<double> o;
    o.push_front(3);
    o.push_back(9);
    o.push_front(12);
    List<double>::Iterator i1 = o.begin();
    ++i1;
    o.pop_front();
    List<double>::Iterator i2 = o.begin();
    ASSERT_TRUE(i1 == i2);
}

TEST(test_it_equal2) {
    List<int> o;
    List<int>::Iterator i1(o.begin());
    List<int>::Iterator i2(o.end());
    ASSERT_TRUE(i1 == i2);
    ASSERT_FALSE(i1 != i2);
    o.push_front(3);
    i1 = o.begin();
    ASSERT_TRUE(i1 != i2);
    ASSERT_FALSE(i1 == i2);
}

TEST(test_minus) {
    List<double> o;
    o.push_front(3);
    o.push_back(9);
    o.push_front(12);
    List<double>::Iterator i1 = o.begin();
    ++i1;
    ++i1;
    --i1;
    o.pop_front();
    List<double>::Iterator i2 = o.begin();
    ASSERT_TRUE(i1 == i2);
}

TEST(test_it_unequal1) {
    List<double> o;
    o.push_front(3);
    o.push_back(9);
    o.push_front(12);
    List<double>::Iterator i1 = o.begin();
    ++i1;
    o.pop_front();
    List<double>::Iterator i2 = o.begin();
    ASSERT_FALSE(i1 != i2);
}

TEST(test_it_unequal2) {
    List<double> o;
    o.push_front(3);
    o.push_back(9);
    o.push_front(12);
    List<double>::Iterator i1 = o.begin();
    List<double>::Iterator i2 = o.begin();
    ++i1;
    ASSERT_TRUE(i1 != i2);
}

TEST(test_erase) {
    List<double> o;
    o.push_front(3);
    o.push_back(9);
    o.push_front(12);

    o.erase(o.begin());
    ASSERT_EQUAL(*(o.begin()), 3);
    List<double>::Iterator i = o.begin();
    ++i;
    o.erase(i);
    ASSERT_EQUAL(*(o.begin()), 3);
}

TEST(test_erase_edge) {
    List<double> o;
    o.push_back(1);

    o.erase(o.begin());
    ASSERT_TRUE(o.empty());
}

TEST(test_erase_edge2) {
    List<double> o;
    o.push_back(1);
    o.push_front(3);
    o.push_back(9);
    List<double>::Iterator i(++o.begin());
    o.erase(i);
    ASSERT_EQUAL(*(o.begin()), 3);
    ASSERT_EQUAL(*(++o.begin()), 9);
    o.erase(o.begin());
    ASSERT_EQUAL(*(o.begin()), 9);
    ASSERT_EQUAL(o.back(), 9);
    o.erase(o.begin());
    ASSERT_TRUE(o.empty());
}

TEST(test_insert) {
    List<double> o;
    o.push_front(3);
    o.push_back(9);
    o.push_front(12);
    List<double>::Iterator i = o.begin();
    ++i;

    o.insert(i, 7);
    ASSERT_EQUAL(*(++o.begin()), 7);
    ASSERT_EQUAL(*(o.begin()), 12);
    ASSERT_EQUAL(*(++++o.begin()), 3);
    --i;
    o.insert(i, 0);
    ASSERT_EQUAL(*(++o.begin()), 0);
}

TEST(test_insert_edge) {
    List<double> o;
    List<double>::Iterator i;
    o.insert(i, 1);
    ASSERT_EQUAL(*(o.begin()), 1);
    i = o.begin();
    o.insert(i, 3);
    o.insert(i, 2);
    ASSERT_EQUAL(*(o.begin()), 3);
    ASSERT_EQUAL(*(++o.begin()), 2);
}

TEST(test_insert_edge2) {
    List<double> o;
    List<double>::Iterator i;
    o.insert(i, 1);
    ASSERT_EQUAL(*(o.begin()), 1);
    i = o.begin();
    o.insert(i, 2);
    ASSERT_EQUAL(*(o.begin()), 2);
    ASSERT_EQUAL(*(++o.begin()), 1);
}

TEST(test_it_copy) {
    List<int> o;
    o.push_back(3);
    o.push_back(9);
    List<int>::Iterator i1 = o.begin();
    List<int>::Iterator i2(i1);
    ASSERT_TRUE(i1 == i2);
    ++i1;
    ASSERT_TRUE(i1 != i2);
    --i1;
    ASSERT_TRUE(i1 == i2);
}

TEST_MAIN()
