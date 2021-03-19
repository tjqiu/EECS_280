// stats.cpp
#include "stats.h"
#include "p1_library.h"
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<double>> summarize(vector<double> v) {
    vector<vector<double>> summaryVector;
    summaryVector.push_back({v[0],0});
    for (size_t i = 0; i < v.size(); ++i) {
        bool ifSame = false;
        for (size_t j = 0; j < summaryVector.size(); ++j) {
            if (v[i] == summaryVector[j][0]) {
                ++summaryVector[j][1];
                ifSame = true;
            }
        }
        if (!ifSame) {
            summaryVector.push_back({v[i],1});
        }
    }
    for (size_t i = 0; i < summaryVector.size() - 1; ++i) {
        for (size_t j = 0; j < summaryVector.size() - 1 - i; ++j) {
            if (summaryVector[j][0] > summaryVector[j + 1][0]) {
                vector<double> temp = summaryVector[j + 1];
                summaryVector[j + 1] = summaryVector[j];
                summaryVector[j] = temp;
            }
        }
    }
    return summaryVector;
}

int count(vector<double> v) {
    int size = static_cast<int>(v.size());
    return size;
}

double sum(vector<double> v) {
    double sum = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        sum += v[i];
    }
    return sum;
}

double mean(vector<double> v) {
    return sum(v)/count(v);
}

double median(vector<double> v) {
    for (size_t i = 0; i < v.size() - 1; ++i) {
        for (size_t j = 0; j < v.size() - 1 - i; ++j) {
            if (v[j] > v[j + 1]) {
                double temp = v[j + 1];
                v[j + 1] = v[j];
                v[j] = temp;
            }
        }
    }
    if (v.size() % 2 == 0) {
        return (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
    }
    else {
        return v[(v.size() - 1) / 2];
    }
}

double mode(vector<double> v) {
    sort(v);
    vector<int> occurTimes;
    vector<double> occurNum;
    occurNum.push_back(v[0]);
    occurTimes.push_back(0);
    for (size_t i = 0; i < v.size(); ++i) {
        bool ifCount = false;
        for (size_t j = 0; j < occurNum.size(); ++j) {
            if (v[i] == occurNum[j]) {
                ++occurTimes[j];
                ifCount = true;
            }
        }
        if (!ifCount) {
            occurNum.push_back(v[i]);
            occurTimes.push_back(1);
        }
    }
    int largestIndex = 0;
    int largestTimes = 0;
    for (size_t i = 0; i < occurNum.size(); ++i) {
        if (occurTimes[i] > largestTimes) {
            largestTimes = occurTimes[i];
            largestIndex = static_cast<int>(i);
        }
    }
    return occurNum[largestIndex];
}

double min(vector<double> v) {
    double minNum = v[0];
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] < minNum) {
            minNum = v[i];
        }
    }
    return minNum;
}

double max(vector<double> v) {
    double maxNum = v[0];
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] > maxNum) {
            maxNum = v[i];
        }
    }
    return maxNum;
}

double stdev(vector<double> v) {
    double squareSum = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        squareSum += (v[i] - mean(v))*(v[i] - mean(v));
    }
    double dev = sqrt(squareSum / (v.size() - 1));
    return dev;
}

double percentile(vector<double> v, double p) {
    sort(v);
    double rank;
    double fractPart;
    double intPart;
    double percentileNum;
    rank = p*(v.size() - 1) + 1;
    fractPart = modf(rank, &intPart);
    if (intPart < v.size()) {
    percentileNum = v[intPart - 1] + fractPart * (v[intPart] - v[intPart - 1]);
    }
    else {
        percentileNum = v[intPart - 1];
    }
    return percentileNum;
}
