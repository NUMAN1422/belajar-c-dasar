
#include <iostream>
#include<chrono>
#include <cstdlib>
#include <limits>

using namespace std;

void log(int result){
    cout << "usia anda sekarang adalah " << result << endl;

}

int main() {
int tahun_kelahiran {};
auto tahun_sekarang = chrono::system_clock::now();
time_t tahun_sekarang_time_t = chrono::system_clock::to_time_t(tahun_sekarang);
tm* tahun_sekarang_tm = localtime(&tahun_sekarang_time_t);
int tahun_sekarang_int = tahun_sekarang_tm->tm_year + 1900;


while(true) {
    cout << "masukan tahun kelahiran anda: ";
    cin >> tahun_kelahiran;

    if(cin.fail()) {
        cout << "input tidak valid. Harap masukkan angka untuk tahun kelahiran." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
    }

    if (tahun_kelahiran > tahun_sekarang_int || tahun_kelahiran <= 1920) {
    cout << "tahun kelahiran tidak valid. Harap masukkan tahun yang benar." << endl;
     continue;
}


else {
int usia = tahun_sekarang_int - tahun_kelahiran;


log(usia);

if(usia<=19){
    cout << "anda masih anak-anak" << endl;
}
if (usia >= 20) {
    cout << "anda sudah dewasa" << endl;
}
if(usia >=40){
    cout << "anda sudah tua" << endl;
}

else {
   
}

break;
}
}
cout << "tekan enter untuk keluar...";//menampilkan pesan untuk memberitahu pengguna agar menekan enter sebelum keluar
cin.clear();
cin.ignore();
cin.get(); 

return 0; 

}
/*program hitung umur ✔ (kamu sudah)
lanjut:
sistem login sederhana
kalkulator
mini ATM*/
