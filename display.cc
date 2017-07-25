#include "display.h"
#include <fstream>
#include <iostream>
#include <memory>
using namespace std;

Display:: Display(string filename) {
    ifstream iff{filename};
    string line;
    int row = 0;
    while (row < 25) {
        display.resize(25);
        getline(iff, line);
        for (int i = 0; i < 79; i ++) {
            display[row].emplace_back(line[i]);
        }
        row ++;
    }
}

Display:: Display() {
    vector<vector<char>> d(25, vector<char>(79, '.'));
    display = d;
    string s1 = "|-----------------------------------------------------------------------------|";
    string s2 = "|                                                                             |";
    string s3 = "| |--------------------------|        |-----------------------|               |";
    string s4 = "| |..........................|        |.......................|               |";
    string s5 = "| |..........................+########+.......................|-------|       |";
    string s6 = "| |..........................|   #    |...............................|--|    |";
    string s7 = "| |..........................|   #    |..................................|--| |";
    string s8 = "| |----------+---------------|   #    |----+----------------|...............| |";
    string s9 = "|            #                 #############                |...............| |";
    string s10 ="|            #                 #     |-----+------|         |1..............| |";
    string s11 ="|            #                 #     |............|         |...............| |";
    string s12 ="|            ###################     |............|   ######+...............| |";
    string s13 ="|            #                 #     |............|   #     |...............| |";
    string s14 ="|            #                 #     |-----+------|   #     |--------+------| |";
    string s15 ="|  |---------+-----------|     #           #          #              #        |";
    string s16 ="|  |.....................|     #           #          #         |----+------| |";
    string s17 ="|  |.....................|     ########################         |...........| |";
    string s18 ="|  |.....................|     #           #                    |...........| |";
    string s19 ="|  |.....................|     #    |------+--------------------|...........| |";
    string s20 ="|  |.....................|     #    |.......................................| |";
    string s21 ="|  |.....................+##########+.......................................| |";
    string s22 ="|  |.....................|          |.......................................| |";
    string s23 ="|  |---------------------|          |---------------------------------------| |";
    string s24 ="|                                                                             |";
    string s25 ="|-----------------------------------------------------------------------------|";
    display[0].assign(s1.begin(), s1.end());
    cout << display[0][10] << endl;
    display[1].assign(s2.begin(), s2.end());
    display[2].assign(s3.begin(), s3.end());
    display[3].assign(s4.begin(), s4.end());
    display[4].assign(s5.begin(), s5.end());
    display[5].assign(s6.begin(), s6.end());
    display[6].assign(s7.begin(), s7.end());
    display[7].assign(s8.begin(), s8.end());
    display[8].assign(s9.begin(), s9.end());
    display[9].assign(s10.begin(), s10.end());
    display[10].assign(s11.begin(), s11.end());
    display[11].assign(s12.begin(), s12.end());
    display[12].assign(s13.begin(), s13.end());
    display[13].assign(s14.begin(), s14.end());
    display[14].assign(s15.begin(), s15.end());
    display[15].assign(s16.begin(), s16.end());
    display[16].assign(s17.begin(), s17.end());
    display[17].assign(s18.begin(), s18.end());
    display[18].assign(s19.begin(), s19.end());
    display[19].assign(s20.begin(), s20.end());
    display[20].assign(s21.begin(), s21.end());
    display[21].assign(s22.begin(), s22.end());
    display[22].assign(s23.begin(), s23.end());
    display[23].assign(s24.begin(), s24.end());
    display[24].assign(s25.begin(), s25.end());
}

char Display::getChar(int row, int col) {
    return display[row][col];
}

void Display::changeChar(int row, int col, char sign) {
    display[row][col] = sign;
}

ostream &operator<<(ostream &out, const Display &d) {
    for (int i = 0; i < 25; i ++) {
        for (int j = 0; j < 79; j ++) {
            out << d.display[i][j];
        }
        out << endl;
    }
    return out;
}


Display::~Display() {
    
}

