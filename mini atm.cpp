#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

string getTime() {
    time_t now = time(0);
    tm * ltm = localtime(&now);

    stringstream ss;
    ss << "["
         << 1900 + ltm->tm_year << "-"
         << setfill('0') << setw(2) << 1 + ltm->tm_mon << "-"
         << setfill('0') << setw(2) << ltm->tm_mday << " "
         << setfill('0') << setw(2) << ltm->tm_hour << ":"
         << setfill('0') << setw(2) << ltm->tm_min << ":"
         << setfill('0') << setw(2) << ltm->tm_sec
         << "]";


    return ss.str();


}



bool inputangka(double &nilai) {
    string input;
    getline (cin, input);

    stringstream ss(input);
if (!(ss >> nilai) ||!(ss.eof()) || nilai <= 0) {

return false;
}
return true;
}


string rupiah(double angka) {
    stringstream ss;
    ss << fixed << setprecision(0) << angka;
    string hasil = ss.str();
    int n = hasil.length() - 3;
    while (n > 0) {
        hasil.insert(n, ".");
        n -= 3;
    }

    return "Rp " + hasil;
}

void simpan(double saldo, vector <string> & riwayat) {
    ofstream fileout("data.txt");
    fileout << saldo << endl;

    for (string r : riwayat) {
        fileout << r << endl;
    }
    fileout.close();
}


int main  () {

vector <string> riwayat;    
double saldo = 100000.0;

ifstream file("data.txt");

if (file.is_open()) {
    file >> saldo;
    file.ignore();

    string line;
    while (getline(file, line)) {
        riwayat.push_back(line);
    }

    file.close();
}

    while (true) {
string pin;
int attempts = 0;

int pilihan;

cout << "----------selamat datang di mini ATM!----------" << endl;

while (attempts < 3) {
    cout << "Masukkan PIN Anda: ";
    getline (cin, pin);

    if (pin == "1234") {
        cout << "PIN benar. Selamat datang!" << endl;
        break;
    } else {
        attempts++;
        cout << "PIN salah. Coba lagi.sisa kesempatan: " << 3 - attempts << endl;
    }

if (attempts == 3) {
        cout << "Anda telah memasukkan PIN salah sebanyak 3 kali. Akun Anda diblokir." << endl;
      
        return 0;
    
}

}

do {
   
    cout << "Pilih transaksi:" << endl;
    cout << "1. Cek Saldo" << endl;
    cout << "2. Tarik Tunai" << endl;
    cout << "3. Setor Tunai" << endl;
    cout << "4. transfer" << endl;
    cout << "5. Riwayat Transaksi" << endl;
    cout << "6. Keluar" << endl;
    cout << "Masukkan pilihan (1-6): ";
  
    string input;
    getline (cin, input);
    stringstream ss(input);
    
    if (!(ss >> pilihan)) {
        cout << "Input tidak valid. Harap masukkan angka antara 1 dan 6." << endl;
        continue;
    }

    if (pilihan < 1 || pilihan > 6 ) {
        cout << "Pilihan tidak valid. Harap masukkan angka antara 1 dan 6." << endl;
        continue;
    }

    switch (pilihan) {
        case 1: {
            cout << "Saldo Anda: " << rupiah(saldo) << endl;
            break;
        }

        case 2: {
            double tarik;
            cout << "Masukkan jumlah yang ingin ditarik: ";

            if (!inputangka(tarik)) {
                cout << "Input tidak valid!\n" << endl;
                continue;
            }

            if (tarik > saldo) {
                cout << "Saldo tidak cukup untuk melakukan penarikan." << endl;
            }
            else {
                saldo -= tarik;
                cout <<"Penarikan berhasil. Saldo baru: " << rupiah(saldo) << endl;
                stringstream ss;
                ss << getTime() << " tarik: -" <<rupiah(tarik);
                riwayat.push_back(ss.str());

               simpan(saldo, riwayat);

                
                cout << "apakah anda ingin melakukan transaksi lain? (y/n): ";
                string lagi;
                getline(cin, lagi);
                if (lagi == "n" || lagi == "N") {
                    cout << "Terima kasih telah menggunakan mini ATM. Sampai jumpa!" << endl;

                    return 0;
                }
            }
            break;
        }
        case 3: {
            double setor;
            cout << "Masukkan jumlah yang ingin disetor: ";

            if (!inputangka(setor)) {
                cout << "Input tidak valid!\n" << endl;
                continue;
            }
                saldo += setor;
                cout <<  "Setoran berhasil. Saldo baru: " << rupiah(saldo) << endl;
                stringstream ss;
                ss << getTime() << " setor: +" << rupiah(setor);
                riwayat.push_back(ss.str());

                simpan(saldo, riwayat);
            
            cout << "apakah anda ingin melakukan transaksi lain? (y/n): ";
            string lagi;
            getline(cin, lagi);
            if (lagi == "n" || lagi == "N") {
                cout << "Terima kasih telah menggunakan mini ATM. Sampai jumpa!" << endl;
                return 0;
            }
            break;
        }
        case 4: {
            double transfer;
            cout << "Masukkan jumlah yang ingin ditransfer: ";

            if (!inputangka(transfer)) {
                cout << "Input tidak valid!\n" << endl;
                continue;
            }

            if (transfer > saldo) {
                cout << "Saldo tidak cukup untuk melakukan transfer." << endl;
            }
            else {
                saldo -= transfer;
                cout << "Transfer berhasil. Saldo baru: " << rupiah(saldo) << endl;
                stringstream ss;
                ss << getTime() << " transfer: -" << rupiah(transfer);
                riwayat.push_back(ss.str());

               simpan(saldo, riwayat);

                
                cout << "apakah anda ingin melakukan transaksi lain? (y/n): ";
                string lagi;
                getline(cin, lagi);
                if (lagi == "n" || lagi == "N") {
                    cout << "Terima kasih telah menggunakan mini ATM. Sampai jumpa!" << endl;

                    return 0;
                }
            }
            break;
        }




        case 5: {
            if (riwayat.empty()) {
                cout << "====Belum ada riwayat transaksi.====\n" << endl;

            }
            else {
                cout << "===Riwayat Transaksi===\n" << endl;
                for (int i = 0; i < riwayat.size(); i++) {
                    cout << i + 1 << ". " << riwayat[i] << endl;
                }
            }
            cout << "sisa saldo: " << rupiah(saldo) << endl;
            break;
        }
        case 6:
            while (true) {
                cout << "Apakah Anda yakin ingin keluar? (y/n): ";
                string konfirmasi;
                getline(cin, konfirmasi);

                if (konfirmasi == "y" || konfirmasi == "Y") {
                    cout << "Terima kasih telah menggunakan mini ATM. Sampai jumpa!" << endl;

                    return 0;
                } else if (konfirmasi == "n" || konfirmasi == "N") {
                    break;
                } else {
                    cout << "Input tidak valid. Harap masukkan 'y' untuk ya atau 'n' untuk tidak." << endl;
                }
            }
            break;
    }

} while (true);

    cout << "kembali ke login...\n" << endl;


}

}
