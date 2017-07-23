#include "display.h"
#include <fstream>
#include "observer.h"
using namespace std;

Display:: Display(string filename) {
    ifstream iff{filename};
    string line;
    int row = 0;
    while (row < 25) {
        getline(iff, line);
        display.resize(30);
        display[row].resize(79);
        for (int i = 0; i < 79; i ++) {
            display[row][i] = line[i];
        }
        row ++;
    }
}

Display:: Display() {
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
    vector<char> v1(s1.begin(), s1.end());
    vector<char> v2(s2.begin(), s2.end());
    vector<char> v3(s3.begin(), s3.end());
    vector<char> v4(s4.begin(), s4.end());
    vector<char> v5(s5.begin(), s5.end());
    vector<char> v6(s6.begin(), s6.end());
    vector<char> v7(s7.begin(), s7.end());
    vector<char> v8(s8.begin(), s8.end());
    vector<char> v9(s9.begin(), s9.end());
    vector<char> v10(s10.begin(), s10.end());
    vector<char> v11(s11.begin(), s11.end());
    vector<char> v12(s12.begin(), s12.end());
    vector<char> v13(s13.begin(), s13.end());
    vector<char> v14(s14.begin(), s14.end());
    vector<char> v15(s15.begin(), s15.end());
    vector<char> v16(s16.begin(), s16.end());
    vector<char> v17(s17.begin(), s17.end());
    vector<char> v18(s18.begin(), s18.end());
    vector<char> v19(s19.begin(), s19.end());
    vector<char> v20(s20.begin(), s20.end());
    vector<char> v21(s21.begin(), s21.end());
    vector<char> v22(s22.begin(), s22.end());
    vector<char> v23(s23.begin(), s23.end());
    vector<char> v24(s24.begin(), s24.end());
    vector<char> v25(s25.begin(), s25.end());
    vector<vector<char>> d{v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25};
    display = d;
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
