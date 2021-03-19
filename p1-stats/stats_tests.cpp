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
#include <limits>
#include <cmath>
#include <iomanip>
using namespace std;

void test_sum_small_data_set();
void test_summarize();
void test_count_normal();
void test_count_empty();
void test_mean();
void test_median_odd();
void test_median_even();
void test_mode_normal();
void test_mode_same();
void test_min_normal();
void test_max_normal();
void test_stdev();
void test_percentile();
void test_summarize_1();
void test_summarize_2();
void test_sum_1();
void test_mean_1();
void test_mean_2();
void test_median_1();
void test_median_2();
void test_mode_1();
void test_min_1();
void test_min_2();
void test_max_1();
void test_max_2();
void test_stdev_1();
void test_percentile_1();
void test_percentile_2();
// Add prototypes for you test functions here.

int main() {
    test_sum_small_data_set();
    test_summarize();
    test_count_normal();
    test_count_empty();
    test_mean();
    test_median_odd();
    test_median_even();
    test_mode_normal();
    test_mode_same();
    test_min_normal();
    test_max_normal();
    test_stdev();
    test_percentile();
    test_summarize_1();
    test_summarize_2();
    test_sum_1();
    test_mean_1();
    test_mean_2();
    test_median_1();
    test_median_2();
    test_mode_1();
    test_min_1();
    test_min_2();
    test_max_1();
    test_max_2();
    test_stdev_1();
    test_percentile_1();
    test_percentile_2();
  // Call your test functions here

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

void test_sum_1() {
    cout << "test_sum_1" << endl;

    vector<double> data;
    data.push_back(1);
    data.push_back(-100);
    data.push_back(0);

    assert(sum(data) == -99);

    cout << "PASS!" << endl;
}

void test_summarize() {
    cout << "test_summarize" << endl;
    vector<double> data;
    data.push_back(1);
    data.push_back(1);
    data.push_back(2);
    data.push_back(9);
    data.push_back(3);
    data.push_back(3);
    vector<vector<double>> correctResult = {{1,2},{2,1},{3,2},{9,1}};
    
    assert(summarize(data) == correctResult);
    
    cout << "PASS!" <<endl;
}

void test_summarize_1() {
    cout << "test_summarize_1" << endl;
    vector<double> data;
    data.push_back(100);
    data.push_back(1);
    data.push_back(1);
    data.push_back(1);
    data.push_back(-100);
    data.push_back(1000);
    vector<vector<double>> correctResult = {{-100,1},{1,3},{100,1},{1000,1}};
    
    assert(summarize(data) == correctResult);
    
    cout << "PASS!" <<endl;
}

void test_summarize_2() {
    cout << "test_summarize_2" << endl;
    vector<double> data;
    data.push_back(0);
    vector<vector<double>> correctResult = {{0,1}};
    
    assert(summarize(data) == correctResult);
    
    cout << "PASS!" <<endl;
}

void test_count_normal() {
    cout << "test_count_normal" << endl;
    vector<double> data;
    data.push_back(1);
    data.push_back(2);
    
    assert(count(data) == 2);
    cout << "PASS!" <<endl;
}

void test_count_empty() {
    cout << "test_count_empty" << endl;
    vector<double> data;
    
    assert(count(data) == 0);
    cout << "PASS!" <<endl;
}

void test_mean() {
    cout << "test_mean" << endl;
    vector<double> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    assert(mean(data) == 2);
    cout << "PASS!" << endl;
}

void test_mean_1() {
    cout << "test_mean_1" << endl;
    vector<double> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(-3);
    assert(mean(data) == 0);
    cout << "PASS!" << endl;
}

void test_mean_2() {
    cout << "test_mean_2" << endl;
    vector<double> data;
    data.push_back(-3);
    assert(mean(data) == -3);
    cout << "PASS!" << endl;
}

void test_median_odd() {
    cout << "test_median_odd" << endl;
    vector<double> data;
    data.push_back(3);
    data.push_back(2);
    data.push_back(5);
    data.push_back(1);
    data.push_back(4);
    assert(median(data) == 3);
    cout << "PASS!" << endl;
}

void test_median_even() {
    cout << "test_median_even" << endl;
    vector<double> data;
    data.push_back(3);
    data.push_back(2);
    data.push_back(1);
    data.push_back(4);
    assert(median(data) == 2.5);
    cout << "PASS!" << endl;
}

void test_median_1() {
    cout << "test_median_1" << endl;
    vector<double> data;
    data.push_back(0);
    assert(median(data) == 0);
    cout << "PASS!" << endl;
}

void test_median_2() {
    cout << "test_median_2" << endl;
    vector<double> data;
    data.push_back(-1);
    data.push_back(1);
    assert(median(data) == 0);
    cout << "PASS!" << endl;
}

void test_mode_normal() {
    cout << "test_mode_normal" << endl;
    vector<double> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(1);
    assert(mode(data) == 1);
    cout << "PASS!" << endl;
}

void test_mode_same() {
    cout << "test_mode_same" << endl;
    vector<double> data;
    data.push_back(2);
    data.push_back(2);
    data.push_back(1);
    data.push_back(1);
    assert(mode(data) == 1);
    cout << "PASS!" << endl;
}

void test_mode_1() {
    cout << "test_mode_1" << endl;
    vector<double> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    data.push_back(-1);
    assert(mode(data) == -1);
    cout << "PASS!" << endl;
}

void test_min_normal() {
    cout << "test_min_normal" << endl;
    vector<double> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(-1);
    data.push_back(0);
    assert(min(data) == -1);
    cout << "PASS!" << endl;
}

void test_min_1() {
    cout << "test_min_1" << endl;
    vector<double> data;
    data.push_back(0);
    assert(min(data) == 0);
    cout << "PASS!" << endl;
}

void test_min_2() {
    cout << "test_min_2" << endl;
    vector<double> data;
    data.push_back(1);
    data.push_back(1);
    data.push_back(-1);
    data.push_back(-1);
    assert(min(data) == -1);
    cout << "PASS!" << endl;
}

void test_max_normal() {
    cout << "test_max_normal" << endl;
    vector<double> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(-1);
    data.push_back(0);
    assert(max(data) == 2);
    cout << "PASS!" << endl;
}

void test_max_1() {
    cout << "test_max_1" << endl;
    vector<double> data;
    data.push_back(0);
    assert(max(data) == 0);
    cout << "PASS!" << endl;
}

void test_max_2() {
    cout << "test_max_2" << endl;
    vector<double> data;
    data.push_back(1);
    data.push_back(1);
    data.push_back(-1);
    data.push_back(-1);
    assert(max(data) == 1);
    cout << "PASS!" << endl;
}

void test_stdev() {
    const double epsilon = 0.00001;
    cout << "test_stdev" << endl;
    vector<double> data;
    data.push_back(6);
    data.push_back(7);
    data.push_back(8);
    data.push_back(9);
    data.push_back(10);
    assert(fabs(stdev(data) - 1.58114) < epsilon);
    cout << "PASS!" << endl;
}

void test_stdev_1() {
    const double epsilon = 0.00001;
    cout << "test_stdev_1" << endl;
    vector<double> data;
    data.push_back(-1);
    data.push_back(1);
    assert(fabs(stdev(data) - 1.41421) < epsilon);
    cout << "PASS!" << endl;
}

void test_percentile() {
    cout << "test_percentile" << endl;
    vector<double> data;
    data.push_back(15);
    data.push_back(20);
    data.push_back(35);
    data.push_back(40);
    data.push_back(50);
    assert(percentile(data,0.4) == 29);
    cout << "PASS!" << endl;
}

void test_percentile_1() {
    cout << "test_percentile_1" << endl;
    vector<double> data;
    data.push_back(35);
    data.push_back(15);
    data.push_back(20);
    data.push_back(50);
    data.push_back(40);
    assert(percentile(data,0.4) == 29);
    assert(percentile(data,1) == 50);
    assert(percentile(data,0) == 15);
    cout << "PASS!" << endl;
}

void test_percentile_2() {
    cout << "test_percentile_2" << endl;
    vector<double> data;
    data.push_back(-5);
    assert(percentile(data,1) == -5);
    assert(percentile(data,0) == -5);
    assert(percentile(data,0.4) == -5);
    cout << "PASS!" << endl;
}
// Add the test function implementations here.
