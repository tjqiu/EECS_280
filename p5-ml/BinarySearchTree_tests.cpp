// Project UID db1f506d06d84ab787baf250c265e24e

#include "BinarySearchTree.h"
#include "unit_test_framework.h"
#include <sstream>

TEST(test_empty_tree) {
    BinarySearchTree<int> bst;
    ASSERT_TRUE(bst.size() == 0);
    ASSERT_TRUE(bst.height() == 0);
    ASSERT_TRUE(bst.find(5) == bst.end());
    ASSERT_TRUE(bst.check_sorting_invariant());
    ASSERT_TRUE(bst.max_element() == bst.end());
    ASSERT_TRUE(bst.min_element() == bst.end());
}

TEST(test_empty) {
    BinarySearchTree<int> bst;
    ASSERT_TRUE(bst.empty());

    bst.insert(1);
    ASSERT_FALSE(bst.empty());
}

TEST(test_default_ctor) {
    BinarySearchTree<int> bst;
    ASSERT_TRUE(bst.empty());
}

TEST(test_height) {
    BinarySearchTree<int> bst;
    ASSERT_EQUAL(bst.height(), 0u);

    bst.insert(1);
    bst.insert(0);
    bst.insert(2);
    ASSERT_EQUAL(bst.height(), 2u);

    bst.insert(-1);
    ASSERT_EQUAL(bst.height(), 3u);

    bst.insert(3);
    bst.insert(-2);
    ASSERT_EQUAL(bst.height(), 4u);
}

TEST(test_size) {
    BinarySearchTree<int> bst;
    ASSERT_EQUAL(bst.size(), 0u);

    bst.insert(1);
    bst.insert(0);
    bst.insert(2);
    ASSERT_EQUAL(bst.size(), 3u);
}

TEST(test_begin_and_end) {
    BinarySearchTree<int> bst;
    ASSERT_EQUAL(bst.begin(), bst.end());
}

TEST(test_check_sorting_invariant1) {
    BinarySearchTree<int> bst;
    ASSERT_TRUE(bst.check_sorting_invariant());

    bst.insert(1);
    ASSERT_TRUE(bst.check_sorting_invariant());

    bst.insert(0);
    *bst.begin() = 2;
    ASSERT_FALSE(bst.check_sorting_invariant());
}

TEST(test_check_sorting_invariant2) {
    BinarySearchTree<int> bst;
    bst.insert(1);

    *bst.begin() = 4;
    ASSERT_TRUE(bst.check_sorting_invariant());
}

TEST(test_check_sorting_invariant3) {
    BinarySearchTree<int> bst;
    bst.insert(4);
    bst.insert(1);
    bst.insert(5);
    bst.insert(0);
    bst.insert(2);
    ASSERT_TRUE(bst.check_sorting_invariant());

    *bst.find(0) = 6;
    *bst.find(1) = 7;
    ASSERT_FALSE(bst.check_sorting_invariant());
}

TEST(test_check_sorting_invariant4) {
    BinarySearchTree<int> bst;
    bst.insert(-1);
    bst.insert(-2);
    bst.insert(-5);
    bst.insert(-10);
    bst.insert(100);
    bst.insert(2);
    bst.insert(10000);
    bst.insert(499);
    bst.insert(123);
    ASSERT_TRUE(bst.check_sorting_invariant());

    *bst.find(-1) = 12222;
    ASSERT_FALSE(bst.check_sorting_invariant());
}

TEST(test_check_sorting_invariant5) {
    BinarySearchTree<int> bst;
    bst.insert(15);
    bst.insert(13);
    bst.insert(11);
    bst.insert(12);
    bst.insert(20);
    bst.insert(9);
    bst.insert(19);
    bst.insert(21);
    bst.insert(23);
    ASSERT_TRUE(bst.check_sorting_invariant());

    *bst.find(15) = 17;
    ASSERT_TRUE(bst.check_sorting_invariant());
    *bst.find(13) = 15;
    ASSERT_TRUE(bst.check_sorting_invariant());
}

TEST(test_find1) {
    BinarySearchTree<int> bst;
    bst.insert(1);

    ASSERT_EQUAL(bst.find(1), bst.begin());
    ASSERT_EQUAL(bst.find(3), bst.end());
}

TEST(test_find2) {
    BinarySearchTree<int> bst;
    bst.insert(1);
    bst.insert(0);
    bst.insert(2);

    ASSERT_EQUAL(bst.find(1), ++(bst.begin()));
    ASSERT_EQUAL(bst.find(2), ++(++(bst.begin())));
}

TEST(test_find3) {
    BinarySearchTree<int> bst;
    bst.insert(4);
    bst.insert(1);
    bst.insert(5);

    ASSERT_EQUAL(bst.find(1), bst.begin());
    ASSERT_EQUAL(bst.find(0), bst.end());

    bst.insert(0);
    ASSERT_EQUAL(bst.find(0), bst.begin());
}

TEST(test_max_element) {
    BinarySearchTree<int> bst;
    ASSERT_EQUAL(bst.max_element(), bst.end());

    bst.insert(1);
    ASSERT_EQUAL(*bst.max_element(), 1);

    bst.insert(0);
    bst.insert(2);
    ASSERT_EQUAL(*bst.max_element(), 2);
}

TEST(test_min_element) {
    BinarySearchTree<int> bst;
    ASSERT_EQUAL(bst.min_element(), bst.end());

    bst.insert(1);
    ASSERT_EQUAL(*bst.min_element(), 1);

    bst.insert(0);
    bst.insert(2);
    ASSERT_EQUAL(*bst.min_element(), 0);
}

TEST(test_traverse_preorder_edge) {
    BinarySearchTree<int> bst;
    std::ostringstream oss;
    bst.traverse_preorder(oss);
    ASSERT_EQUAL(oss.str(), "");
}

TEST(test_traverse_preorder1) {
    BinarySearchTree<int> bst;
    std::ostringstream oss;

    bst.insert(4);
    bst.insert(1);
    bst.insert(5);
    bst.traverse_preorder(oss);
    ASSERT_EQUAL(oss.str(), "4 1 5 ");
}

TEST(test_traverse_preorder2) {
    BinarySearchTree<int> bst;
    std::ostringstream oss;

    bst.insert(4);
    bst.insert(1);
    bst.insert(5);
    bst.insert(0);
    bst.insert(2);
    bst.traverse_preorder(oss);
    ASSERT_EQUAL(oss.str(), "4 1 0 2 5 ");
}

TEST(test_traverse_preorder3) {
    BinarySearchTree<int> bst;
    std::ostringstream oss;

    bst.insert(15);
    bst.insert(13);
    bst.insert(11);
    bst.insert(9);
    bst.insert(19);
    bst.insert(21);
    bst.insert(23);
    bst.traverse_preorder(oss);
    ASSERT_EQUAL(oss.str(), "15 13 11 9 19 21 23 ");
}

TEST(test_traverse_inorder_edge) {
    BinarySearchTree<int> bst;
    std::ostringstream oss;
    bst.traverse_inorder(oss);
    ASSERT_EQUAL(oss.str(), "");
}

TEST(test_traverse_inorder1) {
    BinarySearchTree<int> bst;
    std::ostringstream oss;

    bst.insert(4);
    bst.insert(1);
    bst.insert(5);
    bst.traverse_inorder(oss);
    ASSERT_EQUAL(oss.str(), "1 4 5 ");
}

TEST(test_traverse_inorder2) {
    BinarySearchTree<int> bst;
    std::ostringstream oss;

    bst.insert(4);
    bst.insert(1);
    bst.insert(5);
    bst.insert(0);
    bst.insert(2);
    bst.traverse_inorder(oss);
    ASSERT_EQUAL(oss.str(), "0 1 2 4 5 ");
}

TEST(test_min_greater_than1) {
    BinarySearchTree<int> bst;
    ASSERT_EQUAL(bst.min_greater_than(1), bst.end());

    bst.insert(4);
    bst.insert(1);
    bst.insert(5);
    bst.insert(0);

    ASSERT_EQUAL(*bst.min_greater_than(1), 4);

    bst.insert(2);

    ASSERT_EQUAL(*bst.min_greater_than(1), 2);
    ASSERT_EQUAL(bst.min_greater_than(5), bst.end());
}

TEST(test_assign_operator_edge) {
    BinarySearchTree<int> bst1;
    BinarySearchTree<int> bst2;

    bst2.insert(1);
    ASSERT_EQUAL(bst2.find(1), bst2.begin());
    bst2 = bst1;
    ASSERT_EQUAL(bst2.find(1), bst2.end());
}

TEST(test_assign_operator) {
    BinarySearchTree<int> bst1;
    BinarySearchTree<int> bst2;

    bst1.insert(4);
    bst1.insert(1);
    bst1.insert(5);
    bst1.insert(0);
    bst1.insert(2);

    bst2 = bst1;
    ASSERT_TRUE(bst1.size() == bst2.size());
    ASSERT_TRUE(bst1.height() == bst2.height());

    bst2.insert(-3);
    ASSERT_FALSE(bst1.size() == bst2.size());
    ASSERT_FALSE(bst1.height() == bst2.height());
    ASSERT_EQUAL(bst1.find(-3), bst1.end());
    ASSERT_EQUAL(bst2.find(-3), bst2.begin());
}

TEST(test_destroy) {
    BinarySearchTree<int> bst1;
    BinarySearchTree<int> bst2;
    bst1.insert(4);
    bst1.insert(1);
    bst1.insert(5);
    bst1.insert(0);
    bst1.insert(2);
    ASSERT_EQUAL(bst1.find(0), bst1.begin());
    ASSERT_EQUAL(bst1.height(), 3);
    ASSERT_EQUAL(bst1.size(), 5);

    bst2.insert(10);
    bst1 = bst2;
    ASSERT_EQUAL(bst1.find(0), bst1.end());
    ASSERT_EQUAL(bst1.height(), 1);
    ASSERT_EQUAL(bst1.size(), 1);
}

TEST_MAIN()
