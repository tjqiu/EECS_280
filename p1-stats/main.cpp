//main.cpp
#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    cout << "enter a filename" << endl;
    string fileName;
    cin >> fileName;
    cout << "enter a column name" << endl;
    string columnName;
    cin >> columnName;
    cout << "reading column " << columnName << " from " << fileName << endl;
    cout << "Summary (value: frequency)" << endl;
    vector<double> extractColumn = extract_column(fileName,columnName);
    vector<vector<double>> summary = summarize(extractColumn);
    for (size_t i = 0; i < summary.size(); ++i) {
        cout << summary[i][0] << ": "
        << summary[i][1] << endl;
    }
    cout << endl;
    cout << "count = " << count(extractColumn) << endl;
    cout << "sum = " << sum(extractColumn) << endl;
    cout << "mean = " << mean(extractColumn) << endl;
    cout << "stdev = " << stdev(extractColumn) << endl;
    cout << "median = " << median(extractColumn) << endl;
    cout << "mode = " << mode(extractColumn) << endl;
    cout << "min = " << min(extractColumn) << endl;
    cout << "max = " << max(extractColumn) << endl;
    cout << "  0th percentile = " << percentile(extractColumn,0) << endl;
    cout << " 25th percentile = " << percentile(extractColumn,0.25) << endl;
    cout << " 50th percentile = " << percentile(extractColumn,0.5) << endl;
    cout << " 75th percentile = " << percentile(extractColumn,0.75) << endl;
    cout << "100th percentile = " << percentile(extractColumn,1) << endl;
}
