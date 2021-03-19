// Project UID af1f95f547e44c8ea88730dfb185559d
#include "processing.h"
#include "Image.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream fin;
    fin.open(argv[1]);
    ofstream fout;
    fout.open(argv[2]);
    if (!fin.is_open()) {
        cout << "Error opening file: " << *argv[1] << endl;
        return 1;
    }
    Image* img = new Image;
    Image_init(img, fin);
    if ((argc != 4 && argc != 5) || atoi(argv[3]) <= 0 || atoi(argv[3])
        > Image_width(img)) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
        << "WIDTH and HEIGHT must be less than or equal to original"
        << endl;
        return 1;
    }
    if (argc == 5) {
        if (atoi(argv[4]) <= 0 || atoi(argv[4]) > Image_height(img)) {
            cout
            << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
            << "WIDTH and HEIGHT must be less than or equal to original"
            << endl;
            return 1;
        }
        seam_carve(img, atoi(argv[3]), atoi(argv[4]));
    }
    if (argc == 4) {
        seam_carve(img, atoi(argv[3]), Image_width(img));
    }
    Image_print(img, fout);
    fin.close();
    fout.close();
    delete img;
}
