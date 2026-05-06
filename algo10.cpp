# include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main () {

    float phi = 3.14;
    cout << "Masukkan jari-jari lingkaran: ";
    float r;
    cin >> r;


    while (cin.fail()) {
        cout << "Input tidak valid. Masukkan jari-jari yang valid: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> r;
    }

    while (r <= 0) {
        cout << "Jari-jari tidak boleh negatif atau nol. Masukkan jari-jari yang valid: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> r;
    }



    float  L = phi * r * r;
    cout << "Luas Lingkaran dengan jari-jari " << r << " adalah: " << L << endl;
    return 0;
}