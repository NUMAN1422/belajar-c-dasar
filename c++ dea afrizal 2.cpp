#include <iostream>
using namespace std;

int pertambahan(int x,int y){
    return x + y;
}

int pengurangan(int x,int y){
    return x - y;
}

int perkalian(int x,int y){
    return x * y;
}

int pembagian(int x,int y){
    return x / y;
}

void log(int result){
    cout << "hasil penambahan adalah " << result << endl;
}
void log2(int result2){
    cout << "hasil pengurangan adalah " << result2 << endl;
}
void log3(int result3){
    cout << "hasil perkalian adalah " << result3 << endl;
}
void log4(int result4){
    cout << "hasil pembagian adalah " << result4 << endl;
}

int main() {
    int tambah1 = pertambahan(5,4);
    int tambah2 = pertambahan(10,10);
    int kurang1 = pengurangan(5,4);
    int kurang2 = pengurangan(10,10);
    int kali1 = perkalian(5,4);
    int kali2 = perkalian(10,10);
    int bagi1 = pembagian(5,4);
    int bagi2 = pembagian(10,10);
    
    log(tambah1);
    log(tambah2);
    log2(kurang1);
    log2(kurang2);
    log3(kali1);
    log3(kali2);
    log4(bagi1);
    log4(bagi2);

    return 0;
}