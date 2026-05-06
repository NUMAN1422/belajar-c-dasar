#include <iostream>
#include <limits>

using namespace std;

int main () {
      cout << "----------selamat datang di kalkulator sederhana!----------" << endl;
    char lagi = 'y';
    while (lagi == 'y' || lagi == 'Y')
     {
    double a, b;
    char op;

  
    cout << " silahkan masukan angka pertama: ";
    cin >> a;

    while (cin.fail()) {
        cout << "input tidak valid. Harap masukkan angka." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "masukan angka pertama: ";
        cin >> a;
    }

    cout << "masukan operator (+, -, *, /): ";
    cin >> op;
    while (op != '+' && op != '-' && op != '*' && op != '/') {
        cout << "operator tidak valid. Harap masukkan operator yang benar." << endl;
        cout << "masukan operator (+, -, *, /): ";
        cin >> op;
    }

    cout << "masukan angka kedua: ";
    cin >> b;
    while (cin.fail()) {
        cout << "input tidak valid. Harap masukkan angka." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "masukan angka kedua: ";
        cin >> b;
    }

    if (op == '+') {
        cout << "hasil penjumlahan: " << a + b << endl;
    }
    else if (op == '-') {
        cout << "hasil pengurangan: " << a - b << endl;
    }
    else if (op == '*') {
        cout << "hasil perkalian: " << a * b << endl;
    }
    else if (op == '/') {
        if (b == 0) {
            cout << "error: pembagian dengan nol tidak diperbolehkan." << endl;
        }
        else {
            cout << "hasil pembagian: " << (double)a / b << endl;
        }
    }

    
        cout << "apakah anda ingin melakukan perhitungan lagi? (y/n): ";
        cin >> lagi;
        
            if (lagi == 'n' || lagi == 'N') {
            cout << "terima kasih telah menggunakan kalkulator." << endl;
            break;
        }
        
     }
    }



