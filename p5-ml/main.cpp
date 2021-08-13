// Project UID db1f506d06d84ab787baf250c265e24e

#include <map>
#include <iostream>
#include <string>
#include <set>
#include "csvstream.h"
#include <fstream>

using namespace std;

set<string> unique_words(const string &str) {
 istringstream source(str);
 set<string> words;
 string word;

 while (source >> word) {
   words.insert(word);
 }
 return words;
}


string read_csv_name(char* csv) {
    std::string csv_name = "";
    for (char* i = csv; *i != '\0'; i++) {
        csv_name += *i;
    }
    return csv_name;
}


class classifier {
private:
    int voc_size = 0;
    int example = 0;
    map<string, int> word;
    map<string, int> label;
    map<pair<string, string>, int> csv_map;

public:
    
    void test_data() {
        for (auto p:csv_map) {
            cout << p.first.first << " " << p.first.second << " "
            << p.second << endl;
        }
    }
    
    int get_voc() {
        return voc_size;
    }
    
    int get_example() {
        return example;
    }
    
    map<string, int> get_label() {
        return label;
    }
    
    classifier():voc_size(0),example(0) {
        word.clear();
        label.clear();
        csv_map.clear();
    }
    
    void csv_pair(string name, bool bug) {
        if (bug) {
            cout << "training data:" << endl;
        }
        csvstream csvin(name);
        map<string, string> row;
        while (csvin >> row) {
            if (bug) {
                cout << "  label = " << row["tag"] << ", content = "
                << row["content"] << endl;
            }
            if (label[row["tag"]] >= 1) {
                label[row["tag"]] += 1;
            }
            else {
                label[row["tag"]] = 1;
            }
            example += 1;
            vector<pair<string, string>> post;
            vector<pair<string, int>> count_word;
            set<string> content = unique_words(row["content"]);
            for (auto c:content) {
                if (word[c] >= 1) {
                    word[c] += 1;
                }
                else {
                    word[c] = 1;
                    voc_size++;
                }
                pair<string, string> p;
                p.first = row["tag"];
                p.second = c;
                if (csv_map[p] >= 1) {
                    csv_map[p] += 1;
                }
                else {
                    csv_map[p] = 1;
                }
            }
        }
        cout << "trained on " << example << " examples" << endl;
        if (bug) {
            cout << "vocabulary size = " << voc_size << endl;
        }
        cout << endl;
        if (bug) {
            cout << "classes:" << endl;
            for (auto l:label) {
                cout << "  " << l.first << ", " << l.second
                << " examples, log-prior = "
                << log(float(l.second)/float(example)) << endl;
            }
            cout << "classifier parameters:" << endl;
            for (auto m:csv_map) {
                cout << "  " << m.first.first << ":" << m.first.second
                << ", count = " << m.second << ", log-likelihood = "
                << log(float(m.second)/float(label[m.first.first])) << endl;
            }
            cout << endl;
        }
    }
    
    
    void test(string name) {
        cout << "test data:" << endl;
        csvstream csvin(name);
        map<string, string> row;
        int total_pred = 0;
        int corr_pred = 0;
        while (csvin >> row) {
            total_pred++;
            map<string, float> prob;
            set<string> content = unique_words(row["content"]);
            for (auto l:label) {
                prob[l.first] = log(float(l.second)/float(example));
                for (auto c:content) {
                    pair<string, string> p;
                    p.first = l.first;
                    p.second = c;
                    if (csv_map[p] >= 1) {
                        prob[l.first] += log(float(csv_map[p])
                                             /float(l.second));
                    }
                    else if (word[c] >= 1) {
                        csv_map.erase(p);
                        prob[l.first] += log(float(word[c])/float(example));
                    }
                    else {
                        csv_map.erase(p);
                        word.erase(c);
                        prob[l.first] += log(1.0/float(example));
                    }
                }
            }
            string output = prob.begin()->first;
            float pro = prob.begin()->second;
            for (auto p:prob) {
                if (p.second > pro) {
                    pro = p.second;
                    output = p.first;
                }
            }
            cout << "  correct = " << row["tag"] << ", predicted = "
            << output << ", log-probability score = " << pro << endl
            << "  content = " << row["content"] << endl << endl;
            if (row["tag"] == output) {
                corr_pred++;
            }
        }
        cout << "performance: " << corr_pred << " / " << total_pred
        << " posts predicted correctly" << endl;
    }
};




int main(int argc, char* argv[]) {
    std::cout.precision(3);
    bool bug = false;
    if (argc != 3 && argc != 4) {
        std::cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]"
        << std::endl;
        return 1;
    }
    if (argc == 4) {
        if (strcmp(argv[3], "--debug")) {
            std::cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]"
            << std::endl;
            return 1;
        }
        else {
            bug = true;
        }
    }
    ifstream fin1;
    fin1.open(argv[1]);
    if (!fin1.is_open()) {
        cout << "Error opening file: " << argv[1] << endl;
        return 1;
    }
    ifstream fin2;
    fin2.open(argv[2]);
    if (!fin2.is_open()) {
        cout << "Error opening file: " << argv[2] << endl;
        return 1;
    }
    classifier classifier;
    string train_csv = read_csv_name(argv[1]);
    classifier.csv_pair(train_csv, bug);
    string test_csv = read_csv_name(argv[2]);
    classifier.test(test_csv);
}
