/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

// Precision for floating point comparison
const double epsilon = 0.00001;

void test_sum_small_data_set();

// Add prototypes for you test functions here.
void test_summarize();
void test_count();
void test_sum();
void test_mean();
void test_median();
void test_mode();
void test_min();
void test_max();
void test_stdev();
void test_percentile();

int main() {
    test_sum_small_data_set();
    // Call your test functions here
    test_summarize();
    test_count();
    test_sum();
    test_mean();
    test_median();
    test_mode();
    test_min();
    test_max();
    test_stdev();
    test_percentile();
    
    return 0;
}

void test_sum_small_data_set() {
    cout << "test_sum_small_data_set" << endl;
    
    vector<double> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    assert(sum(data) == 6);
    
    cout << "PASS!" << endl;
}

// Add the test function implementations here.
void test_summarize() {
    cout << "test_summarize" << endl;
    
    // Testcase1
    vector<double> data1;
    data1.push_back(6.5);
    data1.push_back(4.9);
    data1.push_back(2.5);
    data1.push_back(5.0);
    data1.push_back(3.7);
    data1.push_back(4.9);
    vector<vector<double>> data1_return = {{2.5, 1}, {3.7, 1},
                           {4.9, 2}, {5.0, 1}, {6.5, 1}};
    assert(summarize(data1) == data1_return);

    
    // Testcase2
    vector<double> data2;
    data2.push_back(0);
    data2.push_back(6);
    data2.push_back(4.2);
    data2.push_back(-10.8);
    data2.push_back(0);
    data2.push_back(10.8);
    data2.push_back(0);
    data2.push_back(-10.8);
    vector<vector<double>> data2_return = {{-10.8, 2}, {0, 3},
                           {4.2, 1}, {6, 1}, {10.8, 1}};
    assert(summarize(data2) == data2_return);
    
    // Testcase3
    vector<double> data3;
    data3.push_back(0);
    data3.push_back(0);
    data3.push_back(0);
    vector<vector<double>> data3_return = {{0, 3}};
    assert(summarize(data3) == data3_return);
    
    // Testcase4
    vector<double> data4;
    data4.push_back(1.1);
    vector<vector<double>> data4_return = {{1.1, 1}};
    assert(summarize(data4) == data4_return);
    
    cout << "PASS!" << endl;
}

void test_count() {
    cout << "test_count" << endl;
    // Testcase1
    vector<double> data1;
    data1.push_back(6.5);
    data1.push_back(4.9);
    data1.push_back(2.5);
    data1.push_back(5.0);
    data1.push_back(3.7);
    data1.push_back(4.9);
    assert(count(data1) == 6);
    
    // Testcase2
    vector<double> data2;
    assert(count(data2) == 0);
    
    // Testcase3
    vector<double> data3;
    data3.push_back(0);
    data3.push_back(6);
    data3.push_back(4.2);
    data3.push_back(10.8);
    data3.push_back(0);
    data3.push_back(10.8);
    data3.push_back(0);
    data3.push_back(10.8);
    data3.push_back(9);
    data3.push_back(7.1);
    data3.push_back(5.2);
    assert(count(data3) == 11);
    
    // Testcase4
    vector<double> data4;
    data4.push_back(2.2);
    assert(count(data4) == 1);
    
    // Testcase5
    vector<double> data5;
    data5.push_back(-1);
    data5.push_back(-4);
    data5.push_back(0);
    data5.push_back(-2);
    data5.push_back(10.99);
    assert(count(data5) == 5);
    
    cout << "PASS!" << endl;
}

void test_sum() {
    cout << "test_sum" << endl;
    
    // Testcase1
    vector<double> data1;
    data1.push_back(6.5);
    data1.push_back(4.9);
    data1.push_back(2.5);
    data1.push_back(5.0);
    data1.push_back(3.7);
    data1.push_back(4.9);
    assert(abs(sum(data1) - 27.5) < epsilon);
    
    // Testcase2
    vector<double> data2;
    data2.push_back(0);
    data2.push_back(0);
    data2.push_back(0);
    assert(abs(sum(data2) - 0) < epsilon);
    
    // Testcase3
    vector<double> data3;
    data3.push_back(0);
    data3.push_back(6);
    data3.push_back(4.2);
    data3.push_back(10.8);
    data3.push_back(0);
    data3.push_back(10.8);
    data3.push_back(0);
    data3.push_back(10.8);
    data3.push_back(9);
    data3.push_back(7.1);
    data3.push_back(5.2);
    assert(abs(sum(data3) - 63.9) < epsilon);
    
    // Testcase4
    vector<double> data4;
    data4.push_back(-1.1);
    assert(abs(sum(data4) - (-1.1)) < epsilon);
    
    // Testcase5
    vector<double> data5;
    data5.push_back(-1);
    data5.push_back(-4);
    data5.push_back(0);
    data5.push_back(-2);
    data5.push_back(10.99);
    data5.push_back(1.2);
    assert(abs(sum(data5) - 5.19) < epsilon);
    
    cout << "PASS!" << endl;
}

void test_mean() {
    cout << "test_mean" << endl;
    
    // Testcase1
    vector<double> data1;
    data1.push_back(6.5);
    data1.push_back(4.9);
    data1.push_back(2.5);
    data1.push_back(5.0);
    data1.push_back(3.7);
    data1.push_back(4.9);
    assert((mean(data1) - 4.5833333333) < epsilon);
    
    // Testcase2
    vector<double> data2;
    data2.push_back(0);
    data2.push_back(0);
    data2.push_back(0);
    assert(abs(mean(data2) - 0) < epsilon);
    
    // Testcase3
    vector<double> data3;
    data3.push_back(0);
    data3.push_back(6);
    data3.push_back(4.2);
    data3.push_back(10.8);
    data3.push_back(0);
    data3.push_back(10.8);
    data3.push_back(0);
    data3.push_back(10.8);
    data3.push_back(9);
    data3.push_back(7.1);
    data3.push_back(5.2);
    assert((mean(data3) - 5.809090909) < epsilon);
    
    // Testcase4
    vector<double> data4;
    data4.push_back(2.4);
    data4.push_back(18.9);
    data4.push_back(20.5);
    data4.push_back(7.3);
    data4.push_back(15.69);
    assert((mean(data4) - 12.958) < epsilon);
    
    // Testcase5
    vector<double> data5;
    data5.push_back(-1);
    data5.push_back(-4);
    data5.push_back(0);
    data5.push_back(-2);
    data5.push_back(10.99);
    data5.push_back(1.2);
    assert(abs(mean(data5) - 0.865) < epsilon);
    
    // Testcase6
    vector<double> data6;
    data6.push_back(0);
    assert(abs(mean(data6) - 0) < epsilon);
    
    cout << "PASS!" << endl;
}

void test_median() {
    cout << "test_median" << endl;
    
    // Testcase1
    vector<double> data1;
    data1.push_back(6.5);
    data1.push_back(4.9);
    data1.push_back(2.5);
    data1.push_back(5.0);
    data1.push_back(3.7);
    data1.push_back(4.9);
    assert(abs(median(data1) - 4.9) < epsilon);
    
    // Testcase2
    vector<double> data2;
    data2.push_back(0);
    data2.push_back(0);
    data2.push_back(0);
    assert(abs(median(data2) - 0) < epsilon);
    
    // Testcase3
    vector<double> data3;
    data3.push_back(0);
    data3.push_back(6.3);
    data3.push_back(4.2);
    data3.push_back(10.8);
    data3.push_back(0);
    data3.push_back(10.8);
    data3.push_back(0);
    data3.push_back(10.8);
    data3.push_back(9);
    data3.push_back(7.1);
    data3.push_back(5.2);
    assert(abs(median(data3) - 6.3) < epsilon);
    
    // Testcase4
    vector<double> data4;
    data4.push_back(100.865);
    data4.push_back(0);
    data4.push_back(10.26);
    data4.push_back(2.5);
    assert(abs(median(data4) - 6.38) < epsilon);
    
    // Testcase5
    vector<double> data5;
    data5.push_back(-1);
    data5.push_back(-4);
    data5.push_back(0);
    data5.push_back(-2);
    data5.push_back(10.99);
    data5.push_back(1.2);
    assert(abs(median(data5) - (-0.5)) < epsilon);
    
    // Testcase6
    vector<double> data6;
    data6.push_back(0);
    assert(abs(median(data6) - 0) < epsilon);
    
    cout << "PASS!" << endl;
}

void test_mode() {
    cout << "test_mode" << endl;
    
    // Testcase1
    vector<double> data1;
    data1.push_back(6.5);
    data1.push_back(4.9);
    data1.push_back(2.5);
    data1.push_back(5.0);
    data1.push_back(3.7);
    data1.push_back(4.9);
    assert(abs(mode(data1) - 4.9) < epsilon);
    
    // Testcase2
    vector<double> data2;
    data2.push_back(10.8);
    data2.push_back(0);
    data2.push_back(6);
    data2.push_back(-4.2);
    data2.push_back(10.8);
    data2.push_back(-7.5);
    data2.push_back(0);
    data2.push_back(-7.5);
    data2.push_back(0);
    data2.push_back(10.8);
    assert(abs(mode(data2) - (0)) < epsilon);
    
    // Testcase3
    vector<double> data3;
    data3.push_back(3);
    data3.push_back(1);
    data3.push_back(2);
    data3.push_back(-5);
    assert(abs(mode(data3) - (-5)) < epsilon);
    
    // Testcase4
    vector<double> data4;
    data4.push_back(106);
    data4.push_back(-6.2);
    data4.push_back(106);
    data4.push_back(-6.2);
    data4.push_back(106);
    assert(abs(mode(data4) - 106) < epsilon);
    
    // Testcase5
    vector<double> data5;
    data5.push_back(0);
    assert(abs(mode(data5) - 0) < epsilon);
    
    cout << "PASS!" << endl;
}

void test_min() {
    cout << "test_min" << endl;
    
    // Testcase1
    vector<double> data1;
    data1.push_back(6.5);
    data1.push_back(4.9);
    data1.push_back(2.5);
    data1.push_back(5.0);
    data1.push_back(3.7);
    data1.push_back(4.9);
    assert(abs(min(data1) - 2.5) < epsilon);
    
    // Testcase2
    vector<double> data2;
    data2.push_back(-9.9);
    data2.push_back(-3);
    data2.push_back(-108.29);
    data2.push_back(-2.1);
    data2.push_back(-1.05);
    assert(abs(min(data2) - (-108.29)) < epsilon);
    
    // Testcase3
    vector<double> data3;
    data3.push_back(0);
    assert(abs(min(data3) - 0) < epsilon);
    
    // Testcase4
    vector<double> data4;
    data4.push_back(106);
    data4.push_back(-6.2);
    data4.push_back(106);
    data4.push_back(-6.2);
    data4.push_back(106);
    assert(abs(min(data4) - (-6.2)) < epsilon);
    
    cout << "PASS!" << endl;
}

void test_max() {
    cout << "test_max" << endl;
    
    // Testcase1
    vector<double> data1;
    data1.push_back(6.5);
    data1.push_back(4.9);
    data1.push_back(2.5);
    data1.push_back(5.0);
    data1.push_back(3.7);
    data1.push_back(4.9);
    assert(max(data1) == 6.5);
    
    // Testcase2
    vector<double> data2;
    data2.push_back(-9.9);
    data2.push_back(-3);
    data2.push_back(-108.29);
    data2.push_back(-2.1);
    data2.push_back(-1.05);
    assert(abs(max(data2) - (-1.05)) < epsilon);
    
    // Testcase3
    vector<double> data3;
    data3.push_back(0);
    assert(abs(max(data3) - 0) < epsilon);
    
    // Testcase4
    vector<double> data4;
    data4.push_back(106);
    data4.push_back(-6.2);
    data4.push_back(106);
    data4.push_back(-6.2);
    data4.push_back(106);
    assert(abs(max(data4) - 106) < epsilon);
    
    cout << "PASS!" << endl;
}

void test_stdev() {
    cout << "test_stdev" << endl;
    
    // Testcase1
    vector<double> data1;
    data1.push_back(6.5);
    data1.push_back(4.9);
    data1.push_back(2.5);
    data1.push_back(5.0);
    data1.push_back(3.7);
    data1.push_back(4.9);
    assert(abs(stdev(data1) - 1.354129487) < epsilon);
    
    // Testcase2
    vector<double> data2;
    data2.push_back(-9.9);
    data2.push_back(-3);
    data2.push_back(-108.29);
    data2.push_back(-2.1);
    data2.push_back(-1.05);
    assert(abs(stdev(data2) - 46.76312511) < epsilon);
    
    // Testcase3
    vector<double> data3;
    data3.push_back(0);
    data3.push_back(-1);
    assert(abs(stdev(data3) - 0.7071067812) < epsilon);
    
    // Testcase4
    vector<double> data4;
    data4.push_back(106);
    data4.push_back(-6.2);
    data4.push_back(106);
    data4.push_back(-6.2);
    data4.push_back(106);
    assert(abs(stdev(data4) - 61.45447095) < epsilon);
    
    
    cout << "PASS!" << endl;
}

void test_percentile() {
    cout << "test_percentile" << endl;
    
    // Testcase1
    vector<double> data1;
    data1.push_back(6.5);
    data1.push_back(4.9);
    data1.push_back(2.5);
    data1.push_back(5.0);
    data1.push_back(3.7);
    data1.push_back(4.9);
    assert((percentile(data1, 0.25) - 4.3) < epsilon);
    assert((percentile(data1, 0.5) - 4.9) < epsilon);
    assert((percentile(data1, 0.75) - 4.975) < epsilon);
    assert((percentile(data1, 0) - 2.5) < epsilon);
    assert((percentile(data1, 1) - 6.5) < epsilon);
    
    // Testcase2
    vector<double> data2;
    data2.push_back(-9.9);
    data2.push_back(-3);
    data2.push_back(-108.29);
    data2.push_back(-2.1);
    data2.push_back(-1.05);
    assert((percentile(data2, 0.25) - (-9.9)) < epsilon);
    assert((percentile(data2, 0.5) - (-3)) < epsilon);
    assert((percentile(data2, 0) - (-108.29)) < epsilon);
    assert((percentile(data2, 1) - (-1.05)) < epsilon);
    assert((percentile(data2, 0.75) - (-2.1)) < epsilon);
    
    // Testcase3
    vector<double> data3;
    data3.push_back(0);
    assert((percentile(data3, 0.25) - 0) < epsilon);
    assert((percentile(data3, 0.5) - 0) < epsilon);
    assert((percentile(data3, 0) - 0) < epsilon);
    assert((percentile(data3, 1) - 0) < epsilon);
    assert((percentile(data3, 0.75) - 0) < epsilon);
    
    cout << "PASS!" << endl;
}
